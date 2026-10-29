
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> tin, tout, eulerTour, depth;
    vector<vector<int>> ancestorTable;
    vector<int> segmentTree;

    int n, timer, cols;

    // Build Euler Tour iteratively
    void dfs(int root, string &s)
    {
        vector<vector<int>> events;
        events.push_back({root, -1, 0});

        while (!events.empty())
        {
            vector<int> event = events.back();
            events.pop_back();

            int node = event[0];
            int parent = event[1];
            int state = event[2];

            if (state == 0)
            {
                // Entry time
                tin[node] = timer;
                eulerTour[timer] = (1 << (s[node] - 'a'));
                timer++;

                ancestorTable[node][0] = parent;

                if (parent != -1)
                {
                    depth[node] = depth[parent] + 1;
                }

                // Exit event must execute after all children
                events.push_back({node, parent, 1});

                // Push children in reverse order
                for (int i = (int)adj[node].size() - 1; i >= 0; i--)
                {
                    int child = adj[node][i];

                    if (child != parent)
                    {
                        events.push_back({child, node, 0});
                    }
                }
            }
            else
            {
                // Exit time
                tout[node] = timer;
                eulerTour[timer] = (1 << (s[node] - 'a'));
                timer++;
            }
        }
    }

    // Build XOR Segment Tree
    void build(int i, int l, int r)
    {
        if (l == r)
        {
            segmentTree[i] = eulerTour[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, r);

        segmentTree[i] =
            segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    // Point update
    void update(int index, int val, int i, int l, int r)
    {
        if (l == r)
        {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
        {
            update(index, val, 2 * i + 1, l, mid);
        }
        else
        {
            update(index, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] =
            segmentTree[2 * i + 1] ^ segmentTree[2 * i + 2];
    }

    // Range XOR query [start, end]
    int query(int start, int end, int i, int l, int r)
    {
        if (l > end || r < start)
        {
            return 0;
        }

        if (start <= l && r <= end)
        {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return query(start, end, 2 * i + 1, l, mid) ^
               query(start, end, 2 * i + 2, mid + 1, r);
    }

    // Build Binary Lifting Table
    void buildAncestorTable()
    {
        for (int j = 1; j < cols; j++)
        {
            for (int node = 0; node < n; node++)
            {
                int p = ancestorTable[node][j - 1];

                if (p != -1)
                {
                    ancestorTable[node][j] =
                        ancestorTable[p][j - 1];
                }
            }
        }
    }

    // Find LCA
    int getLCA(int u, int v)
    {
        if (depth[u] < depth[v])
        {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < cols; j++)
        {
            if (diff & (1 << j))
            {
                u = ancestorTable[u][j];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int j = cols - 1; j >= 0; j--)
        {
            if (ancestorTable[u][j] != ancestorTable[v][j])
            {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>> &edges,
        string s,
        vector<string> &queries)
    {
        this->n = n;

        adj.assign(n, vector<int>());

        for (int i = 0; i < (int)edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2 * n, 0);

        timer = 0;
        cols = 1;

        while ((1 << cols) <= n)
        {
            cols++;
        }

        ancestorTable.assign(n, vector<int>(cols, -1));

        // Root the tree at node 0
        dfs(0, s);

        buildAncestorTable();

        int N = 2 * n;
        segmentTree.assign(4 * N, 0);
        build(0, 0, N - 1);

        vector<bool> result;

        for (int i = 0; i < (int)queries.size(); i++)
        {
            stringstream ss(queries[i]);

            string type;
            ss >> type;

            if (type == "update")
            {
                int node;
                char c;

                ss >> node >> c;

                s[node] = c;
                int bit = (1 << (c - 'a'));

                // Update entry and exit positions
                update(tin[node], bit, 0, 0, N - 1);
                update(tout[node], bit, 0, 0, N - 1);
            }
            else
            {
                int u, v;
                ss >> u >> v;

                int lca = getLCA(u, v);

                // XOR of root-to-u and root-to-v paths
                int maskU = query(0, tin[u], 0, 0, N - 1);
                int maskV = query(0, tin[v], 0, 0, N - 1);

                int lcaBit = (1 << (s[lca] - 'a'));

                int mask = maskU ^ maskV ^ lcaBit;

                // At most one character may have odd frequency
                result.push_back((mask & (mask - 1)) == 0);
            }
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    string s;
    cin >> s;

    int q;
    cin >> q;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(q);

    for (int i = 0; i < q; i++)
    {
        getline(cin, queries[i]);
    }

    Solution sol;

    vector<bool> answer = sol.palindromePath(n, edges, s, queries);

    cout << "[";

    for (int i = 0; i < (int)answer.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << (answer[i] ? "true" : "false");
    }

    cout << "]\n";

    return 0;
}
