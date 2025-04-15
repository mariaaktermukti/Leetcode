#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, visited, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, visited, path, result);
            path.pop_back();
            visited[i] = false;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (may contain duplicates): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> permutations = sol.permuteUnique(nums);

    cout << "\nUnique permutations:\n";
    for (const auto& perm : permutations) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i != perm.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
