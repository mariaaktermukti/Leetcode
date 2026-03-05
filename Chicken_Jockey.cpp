#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];

        vector<long long> dp(n + 1, 0);
        dp[1] = h[0];
        for (int i = 1; i < n; ++i)
        {
            long long option1 = dp[i] + h[i] - 1; 
            long long option2 = dp[i - 1] + h[i - 1] + max(0LL, h[i] - (long long)i);
            dp[i + 1] = min(option1, option2);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
