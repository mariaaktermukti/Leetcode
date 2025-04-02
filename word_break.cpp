#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << (solution.wordBreak(s1, dict1) ? "true" : "false") << endl; 

    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << (solution.wordBreak(s2, dict2) ? "true" : "false") << endl;  

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (solution.wordBreak(s3, dict3) ? "true" : "false") << endl;  

    return 0;
}
