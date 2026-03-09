#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T; 
    cin >> T;
    while (T--) 
    {
        int A1, B1, A2, B2;
        cin >> A1 >> B1 >> A2 >> B2;

        int V1 = 5*A1 + B1;
        int V2 = 5*A2 + B2;

        if (V1 >= V2 && (V1 - V2) % 6 == 0)
        {
            cout << "Yes\n";
        }      
        else
        {
            cout << "No\n";
        }
            
    }
    return 0;
}
