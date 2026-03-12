#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Tcs;
    if (!(cin >> Tcs))
        return 0;
    while (Tcs--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        vector<int> lo(n), hi(n);
        for (int i = 0; i < n; ++i)
        {
            if (a[i] < b[i])
            {
                lo[i] = a[i];
                hi[i] = b[i];
            }
            else
            {
                lo[i] = b[i];
                hi[i] = a[i];
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            ++LOG;

        vector<vector<int>> outLow(LOG, vector<int>(n, 0));
        vector<vector<int>> outHigh(LOG, vector<int>(n, 0));
        vector<vector<uint8_t>> okLow(LOG, vector<uint8_t>(n, 0));
        vector<vector<uint8_t>> okHigh(LOG, vector<uint8_t>(n, 0));

        for (int s = 0; s < n; ++s)
        {
            outLow[0][s] = lo[s];
            outHigh[0][s] = hi[s];
            okLow[0][s] = 1;
            okHigh[0][s] = 1;
        }

        for (int k = 1; k < LOG; ++k)
        {
            int span = 1 << (k - 1);
            for (int s = 0; s < n; ++s)
            {
                int s2 = s + span;
                if (s2 >= n)
                {
                    okLow[k][s] = okHigh[k][s] = 0;
                    continue;
                }

                if (!okLow[k - 1][s])
                {
                    okLow[k][s] = 0;
                }
                else
                {
                    int x = outLow[k - 1][s];
                    if (x < lo[s2])
                    {
                        okLow[k][s] = okLow[k - 1][s2];
                        if (okLow[k][s])
                            outLow[k][s] = outLow[k - 1][s2];
                    }
                    else if (x < hi[s2])
                    {
                        okLow[k][s] = okHigh[k - 1][s2];
                        if (okLow[k][s])
                            outLow[k][s] = outHigh[k - 1][s2];
                    }
                    else
                    {
                        okLow[k][s] = 0;
                    }
                }

                if (!okHigh[k - 1][s])
                {
                    okHigh[k][s] = 0;
                }
                else
                {
                    int x = outHigh[k - 1][s];
                    if (x < lo[s2])
                    {
                        okHigh[k][s] = okLow[k - 1][s2];
                        if (okHigh[k][s])
                            outHigh[k][s] = outLow[k - 1][s2];
                    }
                    else if (x < hi[s2])
                    {
                        okHigh[k][s] = okHigh[k - 1][s2];
                        if (okHigh[k][s])
                            outHigh[k][s] = outHigh[k - 1][s2];
                    }
                    else
                    {
                        okHigh[k][s] = 0;
                    }
                }
            }
        }

        long long ans = 0;
        for (int l = 0; l < n; ++l)
        {
            ans += 1;

            int Tcur = lo[l];
            int s = l + 1;

            for (int k = LOG - 1; k >= 0; --k)
            {
                int span = 1 << k;
                if (s + span - 1 >= n)
                    continue;

                if (Tcur < lo[s])
                {
                    if (okLow[k][s])
                    {
                        Tcur = outLow[k][s];
                        s += span;
                    }
                }
                else if (Tcur < hi[s])
                {
                    if (okHigh[k][s])
                    {
                        Tcur = outHigh[k][s];
                        s += span;
                    }
                }
                else
                {
                }
            }

            ans += (s - (l + 1));
        }

        cout << ans << '\n';
    }
    return 0;
}