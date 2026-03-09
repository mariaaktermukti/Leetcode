#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;

    for (int i = 0; i < n; ++i)
    {
        v.push_back(i + 1);
    }

    reverse(v.begin(), v.begin() + (n - k + 1));

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}