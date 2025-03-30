#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    
    // Backtracking helper to generate all subsets.
    void backtrack(vector<int>& nums, int start, vector<int>& current) {
        res.push_back(current);
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current);
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, 0, current);
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    for (auto& subset : ans) {
        cout << "[";
        bool first = true;
        for (int num : subset) {
            if (!first) cout << ",";
            cout << num;
            first = false;
        }
        cout << "]" << endl;
    }
    
    return 0;
}
