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

        long long price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }

        long long dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = -1;
        dp[0] = 0;

        for (int day = 0; day < n; day++)
        {
            long long new_dp[n + 1];
            for (int i = 0; i <= n; i++)
                new_dp[i] = -1;

            for (int w = 0; w <= n; w++)
            {
                if (dp[w] < 0)
                    continue;

                int total = w + 1;

                if (new_dp[total] < dp[w])
                {
                    new_dp[total] = dp[w];
                }

                if (total >= 1)
                {
                    long long profit = dp[w] + price[day];
                    if (new_dp[total - 1] < profit)
                    {
                        new_dp[total - 1] = profit;
                    }
                }

                if (total >= 2)
                {
                    long long profit = dp[w] + 2 * price[day];
                    if (new_dp[total - 2] < profit)
                    {
                        new_dp[total - 2] = profit;
                    }
                }
            }

            for (int i = 0; i <= n; i++)
            {
                dp[i] = new_dp[i];
            }
        }

        cout << dp[0] << endl;
    }

    return 0;
}