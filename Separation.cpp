#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int X;
        cin >> N >> X;
        vector<int> arr(N);
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            if (arr[i] == X)
                res = 1;
        }

        if (res == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            sort(arr.begin(), arr.end());
            if (X < arr[0] || X > arr[N - 1])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}