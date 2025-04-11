#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> left(n, 0); 
    vector<int> right(n, 0); 

    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        left[i] = max(left[i - 1], prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        right[i] = max(right[i + 1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, left[i] + right[i]);
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices for " << n << " days: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int result = maxProfit(prices);
    cout << "Maximum profit with at most two transactions: " << result << endl;

    return 0;
}
