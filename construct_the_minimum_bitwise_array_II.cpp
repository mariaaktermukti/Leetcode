#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int &p : nums)
        {
            int remB = (1 << (__builtin_ctz(~p))) >> 1;

            p ^= (remB) | (-(remB == 0) & ~p);
        }
        return nums;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 3, 5, 7};
    vector<int> ans1 = sol.minBitwiseArray(nums1);

    cout << "Output for [2, 3, 5, 7]: ";
    for (int x : ans1)
        cout << x << " ";
    cout << endl;

    return 0;
}
