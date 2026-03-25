#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << -1 << endl;
            continue;
        }
        if (k == n)
        {
            cout << 0 << endl;
            continue;
        }

        long long ans = -1;
        for (int i = 0; i <= 31; ++i)
        {
            long long floor_pile = n >> i;
            if (floor_pile == 0)
            {
                break;
            }
                

            long long denom = (1LL << i);
            long long ceil_pile = (n + denom - 1) >> i;

            if (k == floor_pile || k == ceil_pile)
            {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
