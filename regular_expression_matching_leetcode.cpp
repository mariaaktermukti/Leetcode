#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) 
        {
            if (p[j - 1] == '*') 
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') 
                {
                    dp[i][j] = dp[i][j - 2]; 
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) 
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; 
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;

    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";
    string s3 = "ab", p3 = ".*";
    string s4 = "mississippi", p4 = "mis*is*p*.";

    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"" << endl;
    cout << "Output: " << (solution.isMatch(s1, p1) ? "true" : "false") << endl;

    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"" << endl;
    cout << "Output: " << (solution.isMatch(s2, p2) ? "true" : "false") << endl;

    cout << "Input: s = \"" << s3 << "\", p = \"" << p3 << "\"" << endl;
    cout << "Output: " << (solution.isMatch(s3, p3) ? "true" : "false") << endl;

    cout << "Input: s = \"" << s4 << "\", p = \"" << p4 << "\"" << endl;
    cout << "Output: " << (solution.isMatch(s4, p4) ? "true" : "false") << endl;

    return 0;
}
