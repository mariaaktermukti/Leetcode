#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;

vector<int> adj[MAXN + 1];
int parent[MAXN + 1];
int a[MAXN + 1];
int n;

void dfs(int u, int p)
{
    parent[u] = p;
    int childCount = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        childCount++;
        dfs(v, u);
    }
    if (childCount == 0)
    {
        a[u] = 0; 
    }
    else
    {
        a[u] = (childCount - 1) % 3;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        vector<int> nz;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
                nz.push_back(i);
        }

        if (nz.empty())
        {
            cout << "YES\n";
            continue;
        }

        int cur = nz[0];
        unordered_set<int> path;
        while (cur != 0)
        {
            path.insert(cur);
            cur = parent[cur];
        }

        bool ok = true;
        for (int u : nz)
        {
            if (!path.count(u))
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << "YES\n";
            continue;
        }

        auto depth = [&](int u)
        {
            int d = 0;
            while (u != 0)
            {
                u = parent[u];
                d++;
            }
            return d;
        };

        sort(nz.begin(), nz.end(), [&](int x, int y)
             { return depth(x) < depth(y); });

        for (int i = 0; i < (int)nz.size(); i++)
        {
            int expected = (i % 2 == 0 ? 1 : 2);
            if (a[nz[i]] != expected)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
