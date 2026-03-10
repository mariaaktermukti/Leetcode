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

        int winner = 1;
        int max_speed = 0;

        for (int i = 1; i <= n; i++)
        {
            int d, time;
            cin >> d >> time;

            int speed = d / time;

            if (speed > max_speed)
            {
                max_speed = speed;
                winner = i;
            }
        }

        cout << winner << endl;
    }

    return 0;
}
