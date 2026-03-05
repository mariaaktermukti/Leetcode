#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        vector<int> ans(r + 1, -1);
        vector<char> used(r + 1, 0);

        for (int x = r; x >= 0; --x)
        {
            if (used[x])
                continue;
            int k = 0;
            while ((1 << k) <= x)
                ++k;
            int segL = (1 << k) - 1 - x;
            int segR = (1 << k) - 1;
            if (segL < 0)
                segL = 0;
            for (int y = segL; y <= segR && y <= r; ++y)
            {
                if (!used[y])
                {
                    used[y] = 1;
                    ans[y] = segR - y;
                }
            }
        }

        ll maxSum = (ll)n * ((ll)l + (ll)r);
        cout << maxSum << '\n';
        for (int v = l; v <= r; ++v)
        {
            cout << ans[v] << (v == r ? '\n' : ' ');
        }
    }
    return 0;
}
