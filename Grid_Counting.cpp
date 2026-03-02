#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200000 + 5;
const ll MOD = 998244353;

ll modpow(ll a, ll e)
{
    ll r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

ll fact[MAXN], ifact[MAXN];

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum != n)
        {
            cout << 0 << '\n';
            continue;
        }

        vector<int> cnt(n + 2, 0);
        for (int j = 1; j <= n; j++)
        {
            int r = min(j, n - j + 1);
            cnt[r]++;
        }
        ll ans = 1;
        ll available = 0;
        for (int i = n; i >= 1; i--)
        {
            if (i <= n)
                available += cnt[i];
            int need = a[i];
            if (need > available)
            {
                ans = 0;
                break;
            }
            ans = ans * nCr((int)available, need) % MOD;
            available -= need;
        }

        if (available != 0)
            ans = 0;
        cout << ans % MOD << '\n';
    }
    return 0;
}
