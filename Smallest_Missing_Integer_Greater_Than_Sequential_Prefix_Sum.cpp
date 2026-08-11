#include <bits/stdc++.h>
using namespace std;

int missingInteger(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());

    int sum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            sum += nums[i];
        }
        else
        {
            break;
        }
    }

    // Find the smallest missing integer >= sum
    while (st.count(sum))
    {
        sum++;
    }

    return sum;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int answer = missingInteger(nums);
    cout << "Smallest missing integer: " << answer << endl;

    return 0;
}