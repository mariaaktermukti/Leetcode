#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        ll K;
        cin >> N >> K;

        vector<ll> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        sort(A.begin(), A.end());

        ll total = accumulate(A.begin(), A.end(), 0LL);
        ll x = A[0], y = A[1];
        ll extra = 0;

        if (x == y) 
        {
            extra = K * x;
        } 
        else 
        {
            ll d = y - x;
            while (K > 0 && d > 1) 
            {
                d = (d + 1) / 2;
                extra += x + d;
                --K;
            }
            if (K > 0) 
            {
                extra += K * (x + d);
            }
        }

        cout << (total + extra) << "\n";
    }
    return 0;
}
