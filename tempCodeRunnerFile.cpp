#include <bits/stdc++.h>
using namespace std;

long long sumLSB(long long n)
{
    long long ans = 0;
    for (long long k = 0; (1LL << k) <= n; k++)
    {
        long long cnt = (n >> k) - (n >> (k + 1)); // count of numbers with LSB = 2^k
        ans += (1LL << k) * cnt;
    }
    return ans;
}
bool isPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long res = sumLSB(n);
        if (!isPowerOfTwo(n))
            res--;
        cout << res << "\n";
    }
}