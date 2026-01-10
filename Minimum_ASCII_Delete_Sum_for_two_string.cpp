#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];

    int solve(string& s1, string& s2, int i, int j) {
        if (i == s1.size() && j == s2.size())
            return 0;

        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++)
                sum += s2[k];
            return sum;
        }

        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++)
                sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        int deleteS1 = s1[i] + solve(s1, s2, i + 1, j);
        int deleteS2 = s2[j] + solve(s1, s2, i, j + 1);

        return dp[i][j] = min(deleteS1, deleteS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};

int main() {
    Solution sol;

    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << sol.minimumDeleteSum(s1, s2) << endl;
    return 0;
}

