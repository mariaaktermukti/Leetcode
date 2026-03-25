#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, l;
        cin >> n >> h >> l;
        int r = 0, c = 0, b = 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a <= h && a <= l)
            {
                b++;
            }

            else if (a <= h)
            {
                r++;
            }

            else if (a <= l)
            {
                c++;
            }
        }
        int total = r + b + c;
        int ans = min({total / 2, r + b, c + b});
        cout << ans << endl;
    }
    return 0;
}