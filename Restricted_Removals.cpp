#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), zero(n, -1), one(n, -1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < n && i < m; i++)
        {
            if (i)
            {
                zero[i] = zero[i - 1];
                one[i] = one[i - 1];
            }
            if (b[i])
            {
                one[i] = i;
            }
            else
                zero[i] = i;
        }
        if (n > m)
        {
            for (int i = m; i < n; i++)
            {
                zero[i] = zero[i - 1];
                one[i] = one[i - 1];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] && one[i] != -1 && i - one[i] <= cnt)
            {
                cnt++;
            }
            else if (a[i] == 0 && zero[i] != -1 && i - zero[i] <= cnt)
            {
                cnt++;
            }
        }
        cout << n - cnt << "\n";
    }
    return 0;
}