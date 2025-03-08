#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int min_operations = INT_MAX;
        
        int current_black_blocks = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'B') {
                current_black_blocks++;
            }
        }
        
        for (int i = 0; i <= n - k; ++i) {
            int operations_needed = k - current_black_blocks;
            min_operations = min(min_operations, operations_needed);
            
            if (i + k < n) {
                if (blocks[i] == 'B') {
                    current_black_blocks--;
                }
                if (blocks[i + k] == 'B') {
                    current_black_blocks++;
                }
            }
        }
        
        return min_operations;
    }
};

int main() {
    Solution solution;
    
    string blocks1 = "WBBWWBBWBW";
    int k1 = 7;
    cout << "Output 1: " << solution.minimumRecolors(blocks1, k1) << endl;

    string blocks2 = "WBWBBBW";
    int k2 = 2;
    cout << "Output 2: " << solution.minimumRecolors(blocks2, k2) << endl;

    return 0;
}
