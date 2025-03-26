#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to compute the minimum operations
int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> elements;

    // Flatten the grid into a 1D array
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            elements.push_back(grid[i][j]);
        }
    }

    // Check if it's possible to make all elements equal
    int remainder = elements[0] % x;
    for (int num : elements) {
        if (num % x != remainder) {
            return -1; // If any number has a different remainder, it's impossible
        }
    }

    // Sort the array to find the median
    sort(elements.begin(), elements.end());
    int median = elements[elements.size() / 2];

    // Calculate the number of operations needed to make all elements equal to the median
    int operations = 0;
    for (int num : elements) {
        operations += abs(num - median) / x;
    }

    return operations;
}

int main() {
    int m, n, x;
    cout << "Enter grid dimensions (m n): ";
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    
    cout << "Enter the grid elements:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    cout << "Enter x: ";
    cin >> x;
    
    int result = minOperations(grid, x);
    cout << "Minimum operations: " << result << endl;
    
    return 0;
}
