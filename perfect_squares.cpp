#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX); 
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    
    cout << "Least number of perfect squares: " << numSquares(n) << endl;
    
    return 0;
}
