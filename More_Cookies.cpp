#include <bits/stdc++.h>
using namespace std;
bool fscheck(vector<int>arr,int cookie,int size)
{
    for(int i=0;i<size;i++)
    {
        if (arr[i] < cookie)
        {
            return true;
        }
    }
    return false;
}

bool seccheck(vector<int>arr,int cookie,int size)
{
    for(int i=0;i<size;i++)
    {
        if (arr[i] == cookie)
        {
            return false;
        }
    }
    return true;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
    {
	    int n,c;
	    cin>>n>>c;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)
        {
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    int require=0;
	    int result=0;
	    while(true)
        {
	        if(fscheck(arr,c+require,n)&&seccheck(arr,c+require,n))
            {
	           cout<<require<<endl;
	           break;
	        }
	        else
            {
	            require++;
	            
	        }  
	        
	    }
	    
	}
	
}