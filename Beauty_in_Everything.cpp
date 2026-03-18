#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t; cin>>t;
	while(t--) 
    {
	    int n; 
        cin>>n;
	    string s;
	    cin>>s;
	    
	    int ans=min(n,3);
	    
	    int l=0, cnt0=0,cnt1=0;
	    for(int r=0; r<s.size(); r++) 
        {
	        if(s[r]=='0') 
            {
                cnt0++;
            }
	        else 
            {
                cnt1++;
            }
	        while(l<n && cnt0>1 && cnt1>1) 
            {
	            if(s[l]=='0') 
                {
                    cnt0--;
                }
	            else 
                {
                    cnt1--;
                }
	            l++;
	        }
	        ans=max(ans,cnt0+cnt1);
	    }
	    if(ans<4 && n>3) 
        {
	        for(int i=3; i<n; i++) 
            {
	            if((s[i-3]=='0' && s[i-2]=='1' && s[i-1]=='0' && s[i]=='1') || (s[i-3]=='1' && s[i-2]=='0' && s[i-1]=='1' && s[i]=='0')) ans=4;
	        }
	    }
	    cout<<ans<<endl;
	}

}