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

    int shift = find(nums.begin(), nums.end(), 0) - nums.begin();

    auto ring = [&](int k)
    {
        return nums[(shift + k) % n];
    };

    bool forward = true, backward = true;

    for (int k = 0; k < n; k++)
    {
        if (ring(k) != k)
            forward = false;

        if (ring(k) != (n - k) % n)
            backward = false;
    }

    if (forward)
    {
        cout << min(shift, n - shift + 2) << '\n';
    }
    else if (backward)
    {
        cout << min(shift + 2, n - shift) << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}