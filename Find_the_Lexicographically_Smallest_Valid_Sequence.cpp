#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        // dp[i] = maximum number of characters from the suffix
        // of word2 that can be matched exactly using word1[i...n-1]
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i)
        {
            if (dp[i + 1] < m &&
                word1[i] == word2[m - dp[i + 1] - 1])
            {
                dp[i] = dp[i + 1] + 1;
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> ans;

        int pos = 0;
        bool changed = false;

        // Greedily choose the smallest possible index
        for (int j = 0; j < m; ++j)
        {

            bool found = false;
            int remaining = m - j - 1;

            for (int i = pos; i < n; ++i)
            {

                // After choosing i, the remaining characters
                // must be matched exactly.
                if (dp[i + 1] < remaining)
                    continue;

                // Case 1: Exact match
                if (word1[i] == word2[j])
                {
                    ans.push_back(i);
                    pos = i + 1;
                    found = true;
                    break;
                }

                // Case 2: Use the one allowed modification
                if (!changed)
                {
                    ans.push_back(i);
                    pos = i + 1;
                    changed = true;
                    found = true;
                    break;
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};

int main()
{
    string word1, word2;

    cin >> word1 >> word2;

    Solution sol;

    vector<int> ans = sol.validSequence(word1, word2);

    cout << "[";

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];

        if (i + 1 < ans.size())
            cout << ",";
    }

    cout << "]" << endl;

    return 0;
}