#include <bits/stdc++.h>
using namespace std;

struct Quad
{
    long long a, b, c;
};

bool less_all(const Quad &f, const Quad &g)
{
    long long A = g.a - f.a;
    long long B = g.b - f.b;
    long long C = g.c - f.c;

    if (A == 0)
    {
        if (B == 0)
            return C > 0;
        return false;
    }

    long long D = B * B - 4 * A * C;
    return (A > 0 && D < 0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<Quad> f(n);
        for (auto &x : f)
            cin >> x.a >> x.b >> x.c;

        vector<vector<int>> g(n), rg(n);
        vector<int> indeg(n, 0), indeg2(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (less_all(f[i], f[j]))
                {
                    g[i].push_back(j);
                    rg[j].push_back(i);
                    indeg[j]++;
                    indeg2[i]++;
                }
            }
        }

        vector<int> dp1(n, 1);
        queue<int> q;

        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g[u])
            {
                dp1[v] = max(dp1[v], dp1[u] + 1);
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        vector<int> dp2(n, 1);

        for (int i = 0; i < n; i++)
            if (indeg2[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : rg[u])
            {
                dp2[v] = max(dp2[v], dp2[u] + 1);
                if (--indeg2[v] == 0)
                    q.push(v);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << dp1[i] + dp2[i] - 1 << " ";
        }
        cout << endl;
    }
}