#include <iostream>
#include <vector>
using namespace std;

bool winnerSquareGame(int n)
{
    vector<bool> dp(n + 1, false);

    dp[0] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i - j * j] == false)
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter number of stones: ";
    cin >> n;
    bool result = winnerSquareGame(n);

    if (result)
        cout << "Alice wins" << endl;
    else
        cout << "Alice loses" << endl;

    return 0;
}