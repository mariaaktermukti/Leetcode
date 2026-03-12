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
        string s;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr == 0)
                s += 'a';
            else if (curr == 1)
                s += 'b';
            else if (curr == 2)
                s += 'c';
            else if (curr == 3)
                s += 'd';
            else if (curr == 4)
                s += 'e';
            curr++;
            curr %= 5;
        }
        cout << s << endl;
    }
}