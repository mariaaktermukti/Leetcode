#include <bits/stdc++.h>
using namespace std;

int stoneGameII(vector<int> &piles)
{

    int n = piles.size();
    int totalSum = accumulate(piles.begin(), piles.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {

        for (int m = n; m >= 1; m--)
        {

            int ans = INT_MIN;
            int sum = 0;

            for (int x = 1; x <= 2 * m; x++)
            {

                int idx = i + x - 1;

                if (idx >= n)
                    break;

                sum += piles[idx];

                ans = max(
                    ans,
                    sum - dp[idx + 1][max(m, x)]);
            }

            dp[i][m] = ans;
        }
    }

    int difference = dp[0][1];
    return (totalSum + difference) / 2;
}

int main()
{

    int n;
    cin >> n;

    vector<int> piles(n);

    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int answer = stoneGameII(piles);
    cout << answer << endl;

    return 0;
}