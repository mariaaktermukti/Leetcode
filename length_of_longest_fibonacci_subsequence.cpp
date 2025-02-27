#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int max_len = 0;

        for (int k = 2; k < n; ++k) {
            for (int j = 1; j < k; ++j) {
                int target = arr[k] - arr[j];
                if (index.count(target) && index[target] < j) {
                    int i = index[target];
                    dp[j][k] = dp[i][j] + 1;
                    max_len = max(max_len, dp[j][k]);
                }
            }
        }

        return max_len >= 3 ? max_len : 0;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.lenLongestFibSubseq(arr);
    cout << "Length of longest Fibonacci-like subsequence: " << result << endl;

    return 0;
}
