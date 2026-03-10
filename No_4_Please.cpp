#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
                c1++;
            else if (arr[i] == 2)
                c2++;
            else
                c3++;
        }

        int del = 0;

        del += min(c1, c3);

        if (c2 > 1)
            del += c2 - 1;

        cout << del << endl;
    }
}