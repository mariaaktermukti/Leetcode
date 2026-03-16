#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int cnt_odd = 0, cnt_eve = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (n % i == 0) 
            {
                if (i % 2) 
                {
                    cnt_odd++;
                }
                else 
                {
                    cnt_eve++;
                }
            }
        }
        cout << cnt_odd << " " << cnt_eve << endl;
    }
}