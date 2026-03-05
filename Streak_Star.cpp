#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

void solve() 
{
    long long n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int maxi = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[i] >= v[i - 1]) cnt++;
        else cnt = 1;
        maxi = max(maxi, cnt);
    }
    for(int i = 0; i < n; i++)
    {
        int ans = v[i];
        v[i] *= x;
        int cnt = 1;
        for(int j = 1; j < n; j++)
        {
            if(v[j] >= v[j - 1]) cnt++;
            else cnt = 1;
            maxi = max(maxi, cnt);
        }
        v[i] = ans;
    }
    cout << maxi << endl;
}

signed main() 
{
    int q;
    cin >> q;
    while (q--) 
    {
        solve();
    }
}