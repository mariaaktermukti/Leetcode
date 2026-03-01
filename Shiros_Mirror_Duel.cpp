#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40004;

int n;
int perm[MAXN];
int position[MAXN];

int getMirror(int idx)
{
    return n - idx + 1;
}

pair<int, int> querySwap(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    int u, v;
    cin >> u >> v;
    return {u, v};
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> perm[i];
        position[perm[i]] = i;
    }

    if (n % 2 == 1)
    {
        int mid = (n + 1) / 2;
        while (position[mid] != mid)
        {
            auto res = querySwap(mid, position[mid]);
            int u = res.first, v = res.second;
            swap(perm[u], perm[v]);
            position[perm[u]] = u;
            position[perm[v]] = v;
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        int posLeft = position[i];
        int posRight = position[getMirror(i)];

        if (posLeft + posRight != n + 1)
        {
            auto res = querySwap(posLeft, getMirror(posRight));
            int u = res.first, v = res.second;
            swap(perm[u], perm[v]);
            position[perm[u]] = u;
            position[perm[v]] = v;
        }
    }

    for (int i = 1; i <= n / 2; i++)
    {
        while (position[i] != i || position[getMirror(i)] != getMirror(i))
        {
            if (position[i] != i)
            {
                auto res = querySwap(i, position[i]);
                int u = res.first, v = res.second;
                swap(perm[u], perm[v]);
                position[perm[u]] = u;
                position[perm[v]] = v;
            }
            else
            {
                auto res = querySwap(getMirror(i), position[getMirror(i)]);
                int u = res.first, v = res.second;
                swap(perm[u], perm[v]);
                position[perm[u]] = u;
                position[perm[v]] = v;
            }
        }
    }

    cout << "!" << endl;
    fflush(stdout);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
