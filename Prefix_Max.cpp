#include <bits/stdc++.h>
using namespace std;

int getValue(vector<int> &a)
{
    int n = a.size();
    int mx = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
        sum += mx;
    }
    return sum;
}

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

        int ans = getValue(a);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(a[i], a[j]);
                ans = max(ans, getValue(a));
                swap(a[i], a[j]);
            }
        }

        cout << ans << endl;
    }
}