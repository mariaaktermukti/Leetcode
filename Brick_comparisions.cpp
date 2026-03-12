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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int current_brick = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[current_brick])
            {
                current_brick = i;
            }
        }
        cout << current_brick + 1 << endl;
    }

    return 0;
}