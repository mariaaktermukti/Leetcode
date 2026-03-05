#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int64> g(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> g[i];
        }
        sort(g.begin(), g.end());
        int64 ans = 0;
        for (int i = n - 1; i >= 0; i -= 2)
        {
            ans += g[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
