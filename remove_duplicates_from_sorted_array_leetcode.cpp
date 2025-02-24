#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0; 

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++; 
            nums[uniqueIndex] = nums[i]; 
        }
    }

    return uniqueIndex + 1;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    cout << "k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    cout << "]" << endl;

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);
    cout << "k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) cout << nums2[i] << (i < k2 - 1 ? ", " : "");
    cout << "]" << endl;

    return 0;
}
