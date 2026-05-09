#include <iostream>
using namespace std;

int main()
{
    int t, n, i;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int count[101] = {0};
        int x;

        for (i = 0; i < n; i++)
        {
            cin >> x;
            count[x]++;
        }

        int max = 1;
        for (i = 2; i <= 100; i++)
        {
            if (count[i] > count[max])
            {
                max = i;
            }
        }

        cout << max << endl;
    }

    return 0;
}