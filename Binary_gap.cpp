#include <bits/stdc++.h>
using namespace std;

void solve()
{
    unsigned int n;
    cin >> n;

    int last = -1;
    int ans = 0;
    int pos = 0;

    while (n > 0)
    {
        if (n & 1)
        {
            if (last != -1)
            {
                ans = max(ans, pos - last);
            }
            last = pos;
        }
        n >>= 1;
        pos++;
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}