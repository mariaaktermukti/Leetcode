#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumCount(vector<int>& nums) {
    int positiveCount = 0, negativeCount = 0;
    
    for (int num : nums) {
        if (num > 0) positiveCount++;
        else if (num < 0) negativeCount++;
    }
    
    return max(positiveCount, negativeCount);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maximumCount(nums);
    cout << "Maximum count between positives and negatives: " << result << endl;

    return 0;
}
