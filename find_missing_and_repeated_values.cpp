#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<vector<int>> grid(n, vector<int>(n));

    unordered_set<int> seen;
    long long sum_grid = 0, sum_squares_grid = 0;
    int repeated = -1, missing = -1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            int num = grid[i][j];
            sum_grid += num;
            sum_squares_grid += (long long) num * num;
            
            if (seen.count(num)) {
                repeated = num; 
            }
            seen.insert(num);
        }
    }

    int N = n * n;
    long long sum_total = (long long) N * (N + 1) / 2;
    long long sum_squares_total = (long long) N * (N + 1) * (2 * N + 1) / 6;

    long long diff_sum = sum_grid - sum_total; 
    long long diff_squares = sum_squares_grid - sum_squares_total;

    long long sum_ab = diff_squares / diff_sum; 

    int a = (sum_ab + diff_sum) / 2;
    int b = a - diff_sum;

    cout << a << " " << b << endl; 
    return 0;
}
