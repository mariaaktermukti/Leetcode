#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &v : A)
            cin >> v;
        sort(A.rbegin(), A.rend()); 
        vector<int64> pref(N + 1, 0);
        for (int i = 0; i < N; ++i)
            pref[i + 1] = pref[i] + A[i];

        int maxK = 2 * N;
        vector<int64> ans(maxK + 1, LLONG_MIN);
        ans[0] = 0; 

        for (int t = 0; t <= N; ++t)
        {
            int64 base = pref[t];
            for (int c = 0; c <= t; ++c)
            {
                int K = t + c; 
                if (K > maxK)
                    break;
                int64 extra = 1LL * c * (t - c) + 1LL * c * (c - 1) / 2;
                ans[K] = max(ans[K], base + extra);
            }
        }

        for (int K = 1; K <= maxK; ++K)
            ans[K] = max(ans[K], ans[K - 1]);

        for (int K = 1; K <= maxK; ++K)
            cout << ans[K] << (K == maxK ? '\n' : ' ');
    }
    return 0;
}