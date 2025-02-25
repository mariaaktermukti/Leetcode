#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    // Test cases:
    vector<pair<string, string>> testCases = {
        {"aa", "a"},  
        {"aa", "*"},    
        {"cb", "?a"}    
    };
    
    Solution sol;
    
    for (auto& test : testCases) {
        string s = test.first;
        string p = test.second;
        bool match = sol.isMatch(s, p);
        cout << "s = \"" << s << "\", p = \"" << p << "\" => " 
             << (match ? "true" : "false") << endl;
    }
    
    return 0;
}
