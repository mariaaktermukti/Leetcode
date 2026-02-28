#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long s, k, m;
        cin >> s >> k >> m;
        long long x = m / k;
        long long y = m - x * k;
        long long sand;
        if (s <= k)
        {
            sand = s;
        }
        else
        {
            if (x % 2 == 0)
            {
                sand = s;
            }
            else
            {
                sand = k;
            }
        }
        long long ans = max(0LL, sand - y);
        cout << ans << endl;
    }
    return 0;
}