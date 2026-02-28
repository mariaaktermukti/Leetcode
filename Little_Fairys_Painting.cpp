#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        set<int> st(a.begin(), a.end());
        int d = st.size();

        int ans = INT_MAX;
        for (int x : st)
        {
            if (x >= d)
            {
                ans = min(ans, x);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
