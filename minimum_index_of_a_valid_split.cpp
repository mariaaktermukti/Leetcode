#include <iostream>
#include <vector>

using namespace std;

int minimumIndex(vector<int>& nums) {
    int n = nums.size();

    int x = -1, count = 0;
    for (int num : nums) {
        if (count == 0) {
            x = num;
            count = 1;
        } else {
            count += (num == x) ? 1 : -1;
        }
    }
    count = 0;
    for (int num : nums) {
        if (num == x) {
            count++;
        }
    }
    if (count * 2 <= n) return -1; 

    int leftCount = 0, rightCount = count;

    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == x) {
            leftCount++;
            rightCount--;
        }
        if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
            return i;
        }
    }

    return -1; 
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minimumIndex(nums);
    cout << "Minimum valid split index: " << result << endl;

    return 0;
}
