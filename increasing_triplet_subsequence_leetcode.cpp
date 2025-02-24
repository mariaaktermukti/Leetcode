#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) 
        {
            if (num <= first) 
            {
                first = num; 
            } 
            else if (num <= second) 
            {
                second = num; 
            } 
            else 
            {         
                return true;
            }
        }

        return false; 
    }
};

int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5};
    Solution solution;
    cout << "Test case 1: " << (solution.increasingTriplet(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test case 2: " << (solution.increasingTriplet(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    cout << "Test case 3: " << (solution.increasingTriplet(nums3) ? "true" : "false") << endl;

    vector<int> nums4 = {10, 20, 1, 2, 3};
    cout << "Test case 4: " << (solution.increasingTriplet(nums4) ? "true" : "false") << endl;

    return 0;
}
