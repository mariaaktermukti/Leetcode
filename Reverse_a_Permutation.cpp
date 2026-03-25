#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        bool descending = true;
        for (int i = 1; i < n; i++)
        {
            if (p[i] > p[i - 1])
            {
                descending = false;
                break;
            }
        }

        if (descending)
        {
            for (int x : p)
                cout << x << " ";
            cout << endl;
            continue;
        }

        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i] != n - i)
            {
                pos = i;
                break;
            }
        }

        int target_val = n - pos;
        int target_pos = -1;
        for (int i = pos; i < n; i++)
        {
            if (p[i] == target_val)
            {
                target_pos = i;
                break;
            }
        }

        reverse(p.begin() + pos, p.begin() + target_pos + 1);

        for (int x : p)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}