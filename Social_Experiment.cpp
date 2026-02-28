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
        if (n == 2 || n == 3)
        {
            cout << n << endl;
        }
        else
        {
            cout << (n % 2) << endl;
        }
    }
    return 0;
}