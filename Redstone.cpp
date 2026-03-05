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
            cin >> a[i];

        unordered_set<int> s;
        bool ok = false;
        for (int x : a)
        {
            if (s.count(x))
            {
                ok = true;
                break;
            }
            s.insert(x);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
