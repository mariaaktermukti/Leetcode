#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        int counter = 0;
        int maxlen = 0;
        cin >> N;
        int arr[N];
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        int pivot = 0;
        for (int k = 0; k < N; k++)
        {
            if (N == 1)
            {
                maxlen = 0;
                break;
            }
            if (k == 0)
                continue;
            else
            {
                if ((arr[k] % 2) != (arr[k - 1] % 2))
                {
                    counter++;
                }
            }
            maxlen = max(counter, maxlen);
        }
        cout << maxlen + 1 << endl;
    }
}