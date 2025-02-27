#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int trapped_water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];  
                } else {
                    trapped_water += (left_max - height[left]);  
                }
                left++; 
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];  
                } else {
                    trapped_water += (right_max - height[right]); 
                }
                right--;  
            }
        }
        
        return trapped_water;
    }
};

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    
    vector<int> height(n);
    cout << "Enter heights of bars: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    Solution sol;
    int result = sol.trap(height);
    cout << "Trapped rainwater: " << result << endl;

    return 0;
}
