#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int pre = 0;

        for (int i = 1; i < n; i++)
        {
            if (i >= minJump)
                pre += dp[i - minJump];

            if (i > maxJump)
                pre -= dp[i - maxJump - 1];

            if (pre > 0 && s[i] == '0')
                dp[i] = 1;
        }

        return dp[n - 1];
    }
};

int main()
{
    string s;
    int minJump, maxJump;

    cin >> s >> minJump >> maxJump;

    Solution sol;
    cout << (sol.canReach(s, minJump, maxJump) ? "true" : "false") << endl;

    return 0;
}