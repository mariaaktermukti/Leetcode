#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    int less = 0, equal = 0;

    for (int x : nums)
    {
        if (x < target)
            less++;
        else if (x == target)
            equal++;
    }

    vector<int> ans;

    for (int i = less; i < less + equal; i++)
    {
        ans.push_back(i);
    }

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << ",";
        cout << ans[i];
    }
    cout << "]" << endl;

    return 0;
}