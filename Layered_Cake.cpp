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

        int top[n], bottom[m];

        for (int i = 0; i < n; i++)
        {
            cin >> top[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> bottom[i];
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (bottom[j] < top[i])
                {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}