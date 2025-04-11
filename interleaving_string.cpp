#include <iostream>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size(), l = s3.size();
    if (m + n != l) return false;

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i > 0 && s1[i - 1] == s3[i + j - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j > 0 && s2[j - 1] == s3[i + j - 1])
                dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2, s3;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    cout << "Enter string s3: ";
    cin >> s3;

    bool result = isInterleave(s1, s2, s3);

    if (result)
        cout << "s3 is a valid interleaving of s1 and s2." << endl;
    else
        cout << "s3 is NOT a valid interleaving of s1 and s2." << endl;

    return 0;
}
