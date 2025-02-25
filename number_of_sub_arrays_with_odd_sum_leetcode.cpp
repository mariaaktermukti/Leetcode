#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        int n, x;
        cin >> n >> x;  // Read n and x
        
        vector<int> result;
        int current_or = 0;
        
        // We need to add numbers that OR together to give x
        for (int i = 0; i < n; i++) {
            if ((current_or | i) <= x) {  // Check if we can include i without exceeding x
                result.push_back(i);
                current_or |= i;
            }
            if (current_or == x) {  // Once we reach the OR value of x, fill the rest with 0
                result.resize(n, 0);  // Fill the remaining slots with 0
                break;
            }
        }
        
        // Print the result array
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
