#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int N;
    cin >> N;
    vector<ll> A(N), prefix_sum(N);
    
    cin >> A[0];
    prefix_sum[0] = A[0];
    for (int i = 1; i < N; ++i) 
    {
        cin >> A[i];
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }
    
    int Q;
    cin >> Q;
    while (Q--) 
    {
        ll S;
        cin >> S;
        
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), S);
        if (it == prefix_sum.end()) 
        {
            cout << -1 << '\n';
        } 
        else 
        {
            cout << (it - prefix_sum.begin() + 1) << '\n';
        }
    }
    
    return 0;
}
