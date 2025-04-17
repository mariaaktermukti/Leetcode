#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] == nums[j] && ((i * j) % k == 0)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int result = countPairs(nums, k);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
