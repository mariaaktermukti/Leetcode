#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m; 

        vector<vector<int>> sets(n);
        vector<int> count(m + 1, 0); 

        for (int i = 0; i < n; i++)
        {
            int li;
            cin >> li;
            sets[i].resize(li);
            for (int j = 0; j < li; j++)
            {
                cin >> sets[i][j];
                count[sets[i][j]]++;
            }
        }

        bool all_present = true;
        for (int i = 1; i <= m; i++)
        {
            if (count[i] == 0)
            {
                all_present = false;
                break;
            }
        }

        if (!all_present)
        {
            cout << "NO\n";
            continue;
        }
        int removable = 0;
        for (int i = 0; i < n; i++)
        {
            bool can_remove = true;
            for (int x : sets[i])
            {
                if (count[x] == 1)
                {
                    can_remove = false;
                    break;
                }
            }
            if (can_remove)
                removable++;
        }

        if (removable >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
