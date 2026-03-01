#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    int last = -1e9;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            last = i;
        }
        else
        {
            if (i > last + k)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
