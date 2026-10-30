
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>>
            pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty())
        {
            auto [d, u, r] = pq.top();
            pq.pop();

            if (d > dist[u][r])
                continue;

            if (u == n - 1)
                return d;

            for (auto [v, w] : adj[u])
            {

                int nr;

                if (labels[v] == labels[u])
                    nr = r + 1;
                else
                    nr = 1;

                if (nr > k)
                    continue;

                if (d + w < dist[v][nr])
                {
                    dist[v][nr] = d + w;
                    pq.push({d + w, v, nr});
                }
            }
        }

        return -1;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    string labels;
    cin >> labels;

    cin >> k;

    Solution obj;

    cout << obj.shortestPath(n, edges, labels, k) << endl;

    return 0;
}
