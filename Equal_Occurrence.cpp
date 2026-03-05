#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x >= 1 && x <= n)
                cnt[x]++;
        }
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i] > 0)
            {
                v.push_back(cnt[i]);
            }
                
        }
            
        sort(v.rbegin(), v.rend());

        int ans = 0;
        for (int i = 1; i <= (int)v.size(); ++i)
        {
            ans = max(ans, v[i - 1] * i);
        }
        cout << ans << '\n';
    }
    return 0;
}
