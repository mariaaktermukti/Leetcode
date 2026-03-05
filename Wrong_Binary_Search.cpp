#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        string s_in;
        cin >> n >> s_in;
        string s = " " + s_in;
        vector<int> p(n + 1, -1);
        bool ok = true;

        for (int i = 1; i <= n; ++i)
        {
            if (s[i] == '1')
                p[i] = i;
        }

        int i = 1;
        while (i <= n)
        {
            if (s[i] == '0')
            {
                int l = i;
                while (i <= n && s[i] == '0')
                    ++i;
                int r = i - 1;
                if (l == r)
                { 
                    ok = false;
                    break;
                }
                p[l] = r;
                for (int j = l + 1; j <= r; ++j)
                    p[j] = j - 1;
            }
            else
            {
                ++i;
            }
        }

        if (!ok)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int idx = 1; idx <= n; ++idx)
            {
                if (idx > 1)
                    cout << ' ';
                cout << p[idx];
            }
            cout << '\n';
        }
    }
    return 0;
}
