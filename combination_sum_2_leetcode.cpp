#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) 
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) 
        {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    vector<vector<int>> result1 = solution.combinationSum2(candidates1, target1);

    cout << "Combinations for target = " << target1 << ":\n";
    for (const auto& combination : result1) 
    {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    vector<vector<int>> result2 = solution.combinationSum2(candidates2, target2);

    cout << "\nCombinations for target = " << target2 << ":\n";
    for (const auto& combination : result2) 
    {
        cout << "[";
        for (int num : combination) 
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
