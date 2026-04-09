#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++)
        {
            cin >> L[i] >> R[i];
            L[i]--;
            R[i]--;
        }

        vector<ll> dp(n);

        function<ll(int)> dfs1 = [&](int v)
        {
            if (L[v] == -1)
            {
                return dp[v] = 1;
            }
            return dp[v] = (dfs1(L[v]) + dfs1(R[v]) + 3) % MOD;
        };

        dfs1(0);

        function<void(int)> dfs2 = [&](int v)
        {
            if (L[v] == -1)
                return;

            dp[L[v]] = (dp[L[v]] + dp[v]) % MOD;
            dp[R[v]] = (dp[R[v]] + dp[v]) % MOD;

            dfs2(L[v]);
            dfs2(R[v]);
        };

        dfs2(0);

        for (int i = 0; i < n; i++)
        {
            cout << dp[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}