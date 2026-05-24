#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    int dfs(int i, vector<int> &arr, int d)
    {

        // If already calculated
        if (dp[i] != -1)
            return dp[i];

        int n = arr.size();

        // Minimum count is 1 (current index)
        int ans = 1;

        // Check RIGHT side
        for (int j = i + 1; j <= min(n - 1, i + d); j++)
        {

            // Stop if greater or equal element found
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d));
        }

        // Check LEFT side
        for (int j = i - 1; j >= max(0, i - d); j--)
        {

            // Stop if greater or equal element found
            if (arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(j, arr, d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int> &arr, int d)
    {

        int n = arr.size();

        dp.resize(n, -1);

        int result = 1;

        // Try starting from every index
        for (int i = 0; i < n; i++)
        {
            result = max(result, dfs(i, arr, d));
        }

        return result;
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    Solution obj;

    cout << obj.maxJumps(arr, d) << endl;

    return 0;
}