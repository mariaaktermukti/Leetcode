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

        int last_unsorted = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                last_unsorted = i;
            }
        }

        if (last_unsorted == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << arr[last_unsorted] << endl;
        }
    }

    return 0;
}