#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int l = max(x - y, x - z);
        int r = min(x + y, x + z);

        int res = max(0, r - l + 1);

        if (l <= x && x <= r)
        {
            res--;
        }    

        cout << res << "\n";
    }
}