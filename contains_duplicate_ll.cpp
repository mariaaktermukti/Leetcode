#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> seen;
    
    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(nums[i])) {
            return true;
        }
        
        seen.insert(nums[i]);
        
        if (seen.size() > k) {
            seen.erase(nums[i - k]);
        }
    }
    
    return false;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter k: ";
    cin >> k;

    if (containsNearbyDuplicate(nums, k)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
