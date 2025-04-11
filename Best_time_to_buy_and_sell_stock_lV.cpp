#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 1; j <= k; ++j) {
            int maxDiff = -prices[0]; 
            for (int i = 1; i < n; ++i) {
                dp[i][j] = max(dp[i - 1][j], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[i][j - 1] - prices[i]);
            }
        }
        return dp[n - 1][k]; 
    }
};

int main() {
    int k;
    int n;
    cout << "Enter the maximum number of transactions (k): ";
    cin >> k;

    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter the prices for each day: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(k, prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
