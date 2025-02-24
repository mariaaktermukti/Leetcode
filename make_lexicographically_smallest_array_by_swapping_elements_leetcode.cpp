#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        multiset<int> window;
        vector<int> result(nums); 
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (abs(nums[i] - nums[j]) <= limit && nums[j] < nums[i]) 
                {
                    swap(nums[i], nums[j]); 
                }
            }
        }
        return nums;
    }
};

int main() 
{
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    Solution sol;
    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);

    cout << "Lexicographically smallest array: ";
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
