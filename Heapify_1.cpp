#include <bits/stdc++.h>
using namespace std;

int oddPart(int x)
{
    while (x % 2 == 0)
        x /= 2;
    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;

            if (oddPart(i) != oddPart(x))
            {
                ok = false;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}