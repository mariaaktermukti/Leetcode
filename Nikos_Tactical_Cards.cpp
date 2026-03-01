#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        ll mx = 0, mn = 0;

        for (int i = 0; i < n; i++)
        {
            ll new_mx = max(mx - a[i], b[i] - mn);
            ll new_mn = min(mn - a[i], b[i] - mx);
            mx = new_mx;
            mn = new_mn;
        }

        cout << mx << "\n";
    }
    return 0;
}
