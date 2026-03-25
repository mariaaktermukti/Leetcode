#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
            
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }
            

        vector<ll> s(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
             s[i + 1] = s[i] + b[i];
        } 

        sort(a.begin(), a.end(), greater<ll>());

        ll best = 0;
        int i = 0;
        while (i < n)
        {
            ll strength = a[i];
            int j = i;
            while (j < n && a[j] == strength)
            {
                ++j;
            }
                
            int m = j;
            int t = upper_bound(s.begin(), s.end(), m) - s.begin() - 1;
            ll score = strength * t;
            if (score > best)
            {
                best = score;
            }
                
            i = j;
        }

        cout << best << endl;
    }
    return 0;
}