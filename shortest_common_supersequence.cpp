#include <iostream>
#include <vector>
using namespace std;

// Function to find the LCS (Longest Common Subsequence)
string findLCS(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Construct LCS string
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}

// Function to construct the shortest common supersequence
string shortestCommonSupersequence(string str1, string str2) {
    string lcs = findLCS(str1, str2);
    string scs = "";

    int i = 0, j = 0;
    for (char c : lcs) {
        while (i < str1.size() && str1[i] != c) {
            scs += str1[i++];
        }
        while (j < str2.size() && str2[j] != c) {
            scs += str2[j++];
        }
        scs += c;
        i++, j++;
    }

    while (i < str1.size()) scs += str1[i++];
    while (j < str2.size()) scs += str2[j++];

    return scs;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string result = shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence: " << result << endl;
    return 0;
}
