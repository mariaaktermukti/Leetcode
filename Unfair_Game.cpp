#include <bits/stdc++.h>
using namespace std;

int main()
{
    static long long C[31][31];
    for (int n = 0; n <= 30; n++)
    {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; k++)
        {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int k;
        cin >> n >> k;

        int d = 0;
        while ((1LL << d) < n)
            d++;

        long long answer = 0;

        for (int maxBit = 0; maxBit <= d - 1; maxBit++)
        {
            for (int cntBit = 1; cntBit <= maxBit + 1; cntBit++)
            {
                if (maxBit + cntBit > k)
                {
                    answer += C[maxBit][cntBit - 1];
                }
            }
        }

        if (d + 1 > k)
        {
            answer++;
        }

        cout << answer << "\n";
    }

    return 0;
}
