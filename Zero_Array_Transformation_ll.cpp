#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) 
    {
        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end());  
        vector<int> diff(n + 1, 0); 

        for (int i = 0; i < k; i++) 
        {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        int curr = 0;
        for (int i = 0; i < n; i++) 
        {
            curr += diff[i]; 
            temp[i] -= curr; 
            if (temp[i] > 0) return false; 
        }
        return true;  
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int left = 0, right = queries.size(), ans = -1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (canMakeZero(nums, queries, mid)) 
            {
                ans = mid;
                right = mid - 1;  
            } 
            else 
            {
                left = mid + 1; 
            }
        }
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cin >> q;
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) cin >> queries[i][0] >> queries[i][1] >> queries[i][2];

    Solution sol;
    cout << sol.minZeroArray(nums, queries) << endl;
    return 0;
}
