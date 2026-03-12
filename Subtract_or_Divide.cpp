#include <bits/stdc++.h>

using namespace std;

unordered_map<int, bool> visited;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 != 0)
        {
            cout << (n + 1) / 2 << endl;
        }
        else if (n % 4 == 0)
        {
            cout << 3 * (n / 4) << endl;
        }
        else
        {
            cout << 3 * (n / 4) + 2 << endl;
        }
    }
}