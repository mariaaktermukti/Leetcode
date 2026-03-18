#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve()
{
    set<int> St;
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<int> a(N + 1);
    St.insert(X);
    St.insert(Y);
    if (N == 2 || __gcd(X, Y) == X)
    {
            cout << -1 << "\n";
            return;
    }

    int mid = -1;
    if(X * 2 <= N && St.count(2 * X) == 0)
    {
        mid = 2 * X;
    }
    else
    {
        for(int i = 2; i * i <= X; i++)
        {
            if(X % i == 0)
            {
                int a = i, b = X / i;
                if(St.count(a) == 0 && __gcd(a,X) > __gcd(Y,X))
                {
                    mid = a;
                    break;
                }
                if(St.count(b) == 0 && __gcd(b,X) > __gcd(Y,X))
                {
                    mid = b;
                    break;
                }
            }
        }
    }

    if(mid == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        St.insert(mid);
        a[N] = X;
        a[N - 1] = Y;
        a[N - 2] = mid;
        int temp = 1;
        for(int i = N - 3; i >= 1; i--)
        {
            while(St.count(temp))
            {
                temp++;
            }
            a[i] = temp;
            St.insert(temp);
        }

        for (int i = 1; i <= N - 3; i++)
        {
                if (__gcd(a[i], a[i + 2]) > __gcd(a[i + 1], a[i + 2]))
                {
                    swap(a[i], a[i + 1]);
                }
                else
                {
                    break;
                }
        }
        for (int i = 1; i <= N; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}