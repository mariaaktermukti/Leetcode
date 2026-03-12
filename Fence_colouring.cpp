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
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        vector<int> freq(n + 1, 0);
        int count1 = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 1)
                count1++;
            freq[A[i]]++;
            maxi = max(maxi, freq[A[i]]);
        }
        cout << min(n - count1, 1 + n - maxi) << endl;
    }
    return 0;
}