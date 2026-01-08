#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int solve(int i, int j, vector<int>& a, vector<int>& b) {
    if (i >= a.size() || j >= b.size())
        return -1000000000;

    if (dp[i][j] != INT_MIN)
        return dp[i][j];

    int take_both = a[i] * b[j] + max(0, solve(i + 1, j + 1, a, b));
    int skip_a = solve(i + 1, j, a, b);
    int skip_b = solve(i, j + 1, a, b);

    return dp[i][j] = max({take_both, skip_a, skip_b});
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = INT_MIN;

    cout << solve(0, 0, nums1, nums2) << '\n';

    return 0;
}
