#include <bits/stdc++.h>
using namespace std;

void input(int arr[], int n)
{
}

void output(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        bool ones = true;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] > 1)
            {
                ones = false;
            }
        }

        if (ones)
        {

            if (n % 2 == 0)
            {
                cout << 0 << endl;
            }

            else
            {
                cout << 1 << endl;
            }
        }

        else
        {
            cout << 499122177 << endl;
        }
    }
}