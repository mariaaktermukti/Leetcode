#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
    
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; 
            
            current.push_back(candidates[i]);
    
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);
    cout << "Combinations for target = " << target1 << ":\n";
    for (const auto& combination : result1) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);
    cout << "\nCombinations for target = " << target2 << ":\n";
    for (const auto& combination : result2) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
 
    vector<int> candidates3 = {2};
    int target3 = 1;
    vector<vector<int>> result3 = solution.combinationSum(candidates3, target3);
    cout << "\nCombinations for target = " << target3 << ":\n";
    for (const auto& combination : result3) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
