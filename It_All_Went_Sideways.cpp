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
        vector<long long> a(n), suf(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            suf[i] = min(a[i], suf[i + 1]);
        }

        long long sumA = 0, sumS = 0;
        for (int i = 0; i < n; ++i)
        {
            sumA += a[i];
            sumS += suf[i];
        }

        int bestBlock = 1, curBlock = 1;
        for (int i = 1; i < n; ++i)
        {
            if (suf[i] == suf[i - 1])
                curBlock++;
            else
            {
                bestBlock = max(bestBlock, curBlock);
                curBlock = 1;
            }
        }
        bestBlock = max(bestBlock, curBlock);

        long long ans = sumA - sumS + (bestBlock - 1);
        cout << ans << endl;
    }

    return 0;
}
