#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(int a, int b, int c, int d, int e)
{
    int odd = c + d + e;
    int mx = max({c,d,e});
    int mn = min({c,d,e});
    if (mn >= 1)
        return 1;
    int even = a + b;
    if (odd == 0)
    {
        int cur = 2 * b + a;
        cur %= 3;
        if (cur) return 0;
        return 1;
    }
    else
    {
        if (even >= 2)  return 1;
        if (odd == mx)
        {
            int cur = odd & 1;
            if (e) cur = 0;
            if (even)
            {
                if (cur) return 1;            
                return 0;
            }
            else
            {
                if (cur) return 0;     
                return 1;
            }
        }
        if (odd - mx >= 2) return 1;  
        if (!(odd & 1))
        {
            if (even) return 1;      
            return 0;
        }
        if (e <= 1) return 1;     
        else
        {
            if (even) return 1;     
            return 0;
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    vector<int> pref(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            if ((n - i - 1) & 1) pref[i] = 2;          
            else pref[i] = 1;        
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        pref[i] += pref[i + 1];
        pref[i] %= 3;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int cur = pref[l] - (r + 1 < n ? pref[r + 1] : 0);
        if ((n - 1 - r) & 1)
            cur *= 2;
        cur %= 3;
        cur += 3;
        cur %= 3;
        if ((r - l) & 1)
        {
            if (cur == 1) a++;  
            else if (cur == 2) b++;    
        }
        else
        {
            if (cur == 1) c++;  
            else if (cur == 2) d++;  
            else e++;       
        }
        bool ans = check(a, b, c, d, e);
        if (ans) cout << "YES";     
        else cout << "NO";      
        cout << '\n';
    }
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}