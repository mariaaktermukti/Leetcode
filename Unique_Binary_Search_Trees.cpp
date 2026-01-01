#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[20] = {0};

    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n])
            return dp[n];

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += numTrees(i - 1) * numTrees(n - i);
        }
        return dp[n] = ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    cout << sol.numTrees(n) << endl;
    return 0;
}
