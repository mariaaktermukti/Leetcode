#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; 
            }
        }

        return k; 
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = solution.removeElement(nums1, val1);
    cout << "k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    cout << "]" << endl;

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = solution.removeElement(nums2, val2);
    cout << "k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
