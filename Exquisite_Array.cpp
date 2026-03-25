#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<vector<int>> pos(n);
        for (int i = 0; i < n - 1; i++)
        {
            int d = abs(p[i] - p[i + 1]);
            pos[d].push_back(i);
        }

        vector<int> parent(n), sz(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        auto find = [&](int x) -> int
        {
            while (parent[x] != x)
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        long long total = 0;
        vector<long long> ans(n + 1, 0);

        for (int k = n - 1; k >= 1; k--)
        {
            for (int idx : pos[k])
            {
                int u = find(idx);
                int v = find(idx + 1);
                if (u != v)
                {
                    total -= 1LL * sz[u] * (sz[u] - 1) / 2;
                    total -= 1LL * sz[v] * (sz[v] - 1) / 2;

                    if (sz[u] < sz[v])
                        swap(u, v);
                    parent[v] = u;
                    sz[u] += sz[v];

                    total += 1LL * sz[u] * (sz[u] - 1) / 2;
                }
            }
            ans[k] = total;
        }

        for (int k = 1; k <= n - 1; k++)
        {
            cout << ans[k] << (k == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}