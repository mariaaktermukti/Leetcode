#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int T;
	cin>>T;
	while(T--)
    {
	    int N;
	    cin>>N;
	    vector<vector<int>>edge(N+1);
	    
	    for(int i=0;i<N-1;i++)
        {
	        int u,v;
	        cin>>u>>v;
	        edge[u].push_back(v);
	        edge[v].push_back(u);
	    }
	    
	    bool flag=false;
	    for(int i=0;i<N+1;i++)
        {
	        if(edge[i].size()>=3)
            {
	            flag=true;
	            break;
	        }
	    }
	    if(flag)
        {
	        cout<<N+1<<endl;
	    }
        else
        {
	        cout<<N+(N-1)<<endl;
	    }
	}
	return 0;

}