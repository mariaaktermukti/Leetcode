#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t = 1;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        unordered_set<ll> s;
        
        int ind1 = s1.length()-1, ind2 = s2.length()-1;
        
        while(ind1 >= 0 && ind2 >= 0)
        {
            if(s1[ind1] == s2[ind2])
            {
                s.insert(ind1);
                ind1--;
                ind2--;
            }
            else
            {
                ind1--;
            }
        }
        
        if(ind2 >= 0)
        {
            cout << -1 << endl;
            continue;
        }
        
        ll sum{}, ind{1};
        for(int i{}; i<s1.length(); i++)
        {
            if(s.find(i) == s.end())
            {
                sum += ind;
            }
            else
            {
                ind++;
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}