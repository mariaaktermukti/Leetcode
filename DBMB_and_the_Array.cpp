#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        vector<int> a(n);
        int sum_a = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum_a += a[i];
        }

        if (s == sum_a)
        {
            cout << "YES" <<endl;
        }
        else if (s < sum_a)
        {
            cout << "NO" << endl;
        }
        else
        {
            int diff = s - sum_a;
            if (diff % x == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}