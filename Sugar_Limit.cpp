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
        int arr[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }
        vector < int > brr(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> brr[i];
        }

        int maxl = * max_element(brr.begin(), brr.end());
        int s = 0;
        int ans = INT_MIN;

        for (int l = 1; l <= maxl; l++) 
        {
            s = 0;
            for (int i = 0; i < n; i++) 
            {

                if (brr[i] <= l && arr[i] > 0) 
                {
                    s += arr[i];
                }
            }
            ans = max(ans, s - l);

        }
        if (ans < 0) 
        {
            cout << 0 << '\n';
        }
        else 
        {
            cout << ans << "\n";
        }
    }

}