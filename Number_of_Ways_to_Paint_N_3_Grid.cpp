#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfWays(int n)
    {
        const int MOD = 1e9 + 7;

        long long dpA = 6;
        long long dpB = 6;

        for (int i = 2; i <= n; i++)
        {
            long long newA = (2 * dpA + 2 * dpB) % MOD;
            long long newB = (2 * dpA + 3 * dpB) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.numOfWays(n) << endl;

    return 0;
}
