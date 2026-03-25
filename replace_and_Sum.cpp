#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<long long> dp(n);
        dp[n - 1] = max(a[n - 1], b[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max({(long long)a[i], (long long)b[i], dp[i + 1]});
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + dp[i];
        }

        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << prefix[r + 1] - prefix[l] << " ";
        }
        cout << "\n";
    }

    return 0;
}