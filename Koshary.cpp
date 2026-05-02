#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 1 && y % 2 == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}