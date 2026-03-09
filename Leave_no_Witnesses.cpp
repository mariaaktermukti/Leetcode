#include <bits/stdc++.h>
using namespace std;

bool check(int n) 
{
    if (n <= 0) 
    {
        return false;
    }

    return (n & (n - 1)) == 0;
}


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        if(check(n))
        {
            cout<<"-1"<<endl;
            continue;
        }
        
        int ans=0;
        for(int i=1;i<=n;i<<=1)
        {
            if(s[i-1]=='0') ans++;
        }
        
        int x=0;
        
        for(int i=n;i>=1;i--)
        {
            if((i&x) != i)
            {
                if(s[i-1] =='1') 
                {
                    ans++;
                }
                x=i;
            }
        }
        
        cout<<ans<<endl;
    }
}