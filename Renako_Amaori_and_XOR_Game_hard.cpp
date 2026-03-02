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
        vector<int> a(n), b(n);
        long long X = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            X ^= a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            X ^= b[i];
        }

        if (X == 0)
        {
            cout << "Tie\n";
            continue;
        }

        int k = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            if ((X >> bit) & 1LL)
            {
                k = bit;
                break;
            }
        }

        int last = -1;
        for (int i = 0; i < n; ++i)
        {
            int ai = (a[i] >> k) & 1;
            int bi = (b[i] >> k) & 1;
            if (ai != bi)
                last = i;
        }

        if (last == -1)
        {
            cout << "Tie\n";
        }
        else
        {
            if ((last & 1) == 0)
                cout << "Ajisai\n";
            else
                cout << "Mai\n";
        }
    }
    return 0;
}
