#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
	ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        set <ll> l,r;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=k;i<n;i++)
        {
            r.insert(a[i]);
        }
        ll ans=0;
        ll sum=0;
        ll cnt=(n-k+1)/2;
        ll flag=(n-k)%2;
        while(l.size()<cnt)
        {
            l.insert(*r.begin());
            sum+=*r.begin();
            r.erase(r.begin());
        }
        ans=2*sum-flag*(*l.rbegin());
        for(int i=k;i<n;i++)
        {
            if(a[i-k]>(*l.rbegin()))
            {
                r.insert(a[i-k]);
            }
            else
            {
                r.insert(*l.rbegin());
                sum-=(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
                l.insert(a[i-k]);
                sum+=a[i-k];
            }
            if(l.count(a[i]))
            {
                sum-=a[i];
                l.erase(l.find(a[i]));
                l.insert(*r.begin());
                sum+=(*r.begin());
                r.erase(r.begin());
            }
            else
            {
                r.erase(r.find(a[i]));
            }
            ans=max(ans,2*sum-flag*(*l.rbegin()));
        }
        cout<<ans<<"\n";
    }
}