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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<long long> pref(n + 1, 0), suff(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + a[i];
        for (int i = n - 1; i >= 0; --i)
            suff[i] = suff[i + 1] + a[i];

        long long ans = 0;
        long long mx = a[n - 1];
        for (int k = 0; k <= n - 1; ++k)
        {
            auto s = mx + pref[k];
            auto avg = s / (k + 1);
            auto diff = llabs(mx - avg);
            ans = max(ans, diff);
            diff = llabs(avg - a[n - 1]);
            ans = max(ans, diff);
        }
        long long mn = a[0];
        for (int k = 0; k <= n - 1; ++k)
        {
            auto s = mn + suff[n - k];
            auto avg = s / (k + 1);
            auto diff = llabs(mn - avg);
            ans = max(ans, diff);
            diff = llabs(avg - a[0]);
            ans = max(ans, diff);
        }
        cout << ans << "\n";
    }
}
