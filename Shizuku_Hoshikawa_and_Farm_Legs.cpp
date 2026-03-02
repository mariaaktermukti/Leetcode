#include <iostream>
using namespace std;

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
            cout << 0 << endl;
        }
        else
        {
            cout << n / 4 + 1 << endl;
        }
    }

    return 0;
}
