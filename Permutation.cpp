#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }    
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]); 
        backtrack(nums, result, start + 1); 
        swap(nums[start], nums[i]); 
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}
int main() {
    vector<int> nums = {1, 2, 3}; 
    vector<vector<int>> permutations = permute(nums);
    cout << "Permutations:\n";
    for (const auto& perm : permutations) {
        cout << "[";
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i] << (i < perm.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}
