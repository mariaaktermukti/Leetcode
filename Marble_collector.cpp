#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        set<int> collected;
        for (int i = 0; i < n; i++) 
        {
            int marble;
            cin >> marble;
            collected.insert(marble);  
        }
        int not_collected = m - collected.size(); 
        cout << not_collected << endl;
    }
}