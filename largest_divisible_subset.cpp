#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
    int n = nums.size();
    if (n == 0) return {};
    
    sort(nums.begin(), nums.end());
    
    vector<int> dp(n, 1);    
    vector<int> prev(n, -1);   

    int maxIndex = 0;        

    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) 
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) 
        {
            maxIndex = i;
        }
    }

    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev[i]) 
    {
        result.push_back(nums[i]);
        if (prev[i] == -1) break;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (positive integers): ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> nums[i];
    }

    vector<int> result = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
