#include <iostream>
#include <vector>
using namespace std;

void subsetXORSum(vector<int>& nums, int index, int currentXOR, int& totalXOR) {
    if (index == nums.size()) {
        totalXOR += currentXOR;
        return;
    }

    subsetXORSum(nums, index + 1, currentXOR ^ nums[index], totalXOR);
    
    subsetXORSum(nums, index + 1, currentXOR, totalXOR);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int totalXOR = 0;
    subsetXORSum(nums, 0, 0, totalXOR);

    cout << "Sum of all XOR totals for every subset: " << totalXOR << endl;

    return 0;
}
