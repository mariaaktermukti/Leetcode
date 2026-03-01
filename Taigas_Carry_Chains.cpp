#include <bits/stdc++.h>
using namespace std;

static const long long INF = 1e18;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        int pc = __builtin_popcountll(n);

        if (k >= 32)
        {
            cout << pc + k - 1 << "\n";
            continue;
        }

        vector<int> bits;
        while (n > 0)
        {
            bits.push_back(n & 1);
            n >>= 1;
        }
        int B = bits.size();

        vector<vector<vector<long long>>> dp(
            B + 1,
            vector<vector<long long>>(k + 1, vector<long long>(2, INF)));

        dp[0][0][0] = 0;

        for (int i = 0; i < B; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                for (int c = 0; c <= 1; c++)
                {
                    if (dp[i][j][c] == INF)
                        continue;

                    {
                        int ti = bits[i] + c;
                        int nc = ti >> 1;
                        int nb = ti & 1;
                        dp[i + 1][j][nc] = min(
                            dp[i + 1][j][nc],
                            dp[i][j][c] + nb);
                    }

                    if (j + 1 <= k)
                    {
                        int ti = bits[i] + c + 1;
                        int nc = ti >> 1;
                        int nb = ti & 1;
                        dp[i + 1][j + 1][nc] = min(
                            dp[i + 1][j + 1][nc],
                            dp[i][j][c] + nb);
                    }
                }
            }
        }

        long long min_pop = INF;
        for (int j = 0; j <= k; j++)
        {
            for (int c = 0; c <= 1; c++)
            {
                if (dp[B][j][c] == INF)
                    continue;
                min_pop = min(min_pop, dp[B][j][c] + c);
            }
        }

        long long result = pc + k - min_pop;
        cout << result << "\n";
    }

    return 0;
}
