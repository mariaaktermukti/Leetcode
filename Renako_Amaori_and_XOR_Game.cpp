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
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }    
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        int total_xor = 0;
        for (int i = 1; i <= n; ++i)
        {
            total_xor ^= a[i];
            total_xor ^= b[i];
        }

        if (total_xor == 0)
        {
            cout << "Tie\n";
            continue;
        }

        int last_diff = -1;
        for (int i = n; i >= 1; --i)
        {
            if (a[i] != b[i])
            {
                last_diff = i;
                break;
            }
        }

        if (last_diff == -1)
        {
            cout << "Tie\n";
        }
        else if (last_diff % 2 == 1)
        {
            cout << "Ajisai\n";
        }
        else
        {
            cout << "Mai\n";
        }
    }

    return 0;
}
