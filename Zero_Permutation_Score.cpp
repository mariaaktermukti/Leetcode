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
        int cnt = 0;
        for (int i = 1; i < n - 1; i += 2)
        {
            cnt += (n - 1 - i - 1);
        }
        cout << cnt << endl;
    }
}
