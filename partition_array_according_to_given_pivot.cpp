#include <iostream>
#include <vector>

using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> less, equal, greater;

    for (int num : nums) {
        if (num < pivot) {
            less.push_back(num);
        } else if (num == pivot) {
            equal.push_back(num);
        } else {
            greater.push_back(num);
        }
    }

    vector<int> result;
    result.insert(result.end(), less.begin(), less.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), greater.begin(), greater.end());

    return result;
}

int main() {
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> result = pivotArray(nums, pivot);

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
