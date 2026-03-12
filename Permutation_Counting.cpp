#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 998244353;
int pw(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 != 0)
            res = 1LL * res * a % mod;
        b /= 2;
        a = 1LL * a * a % mod;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int N = 2e5 + 1;
    vector<int> fact(N, 1), inv_fact(N, 1);
    for (int i(2); i < N; ++i)
    {
        fact[i] = 1LL * fact[i - 1] * i % mod;
        inv_fact[i] = pw(fact[i], mod - 2);
    }

    auto nCr = [&](int n, int r) -> int
    {
        if (r > n)
            return 0;
        int res = fact[n];
        res = 1LL * res * inv_fact[n - r] % mod;
        res = 1LL * res * inv_fact[r] % mod;
        return res;
    };

    vector<int> dp{0, 1, 0, 2, 4, 8, 80};
    while (t--)
    {
        int n, K;
        cin >> n >> K;
        if (n <= 6)
            cout << dp[n] << endl;
        else
        {
            int c1 = n / 3, c3, c2;
            c2 = c1, c3 = c1;
            if (n % 3 == 1)
                ++c2;
            if (n % 3 == 2)
            {
                ++c2;
                ++c3;
            }

            int ans = 0;
            for (int c = c1 - 1; c <= c1 + 1; ++c)
            {
                for (int x = 1; x < c; ++x)
                {
                    int y = c - x;
                    int tmp = 1LL * nCr(c2 - 1, x - 1) * nCr(c3 - 1, y - 1) % mod;
                    tmp = 1LL * tmp * nCr(c, x) % mod;
                    ans += tmp;
                    ans %= mod;
                    if (c == c1)
                        ans += tmp;
                    ans %= mod;
                }
            }
            ans = 1LL * (1LL * (1LL * fact[c1] * fact[c2] % mod) * fact[c3] % mod) * ans % mod;
            cout << ans << endl;
        }
    }

    return 0;
}