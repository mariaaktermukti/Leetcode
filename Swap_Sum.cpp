#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node 
{ 
    ll cost0, cost1; int f0, f1; 
};
int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        ll K;
        cin >> N >> K;
        vector<ll> A(N+1), B(N+1);
        for (int i = 1; i <= N; ++i) 
        {
            cin >> A[i];
        }
        for (int i = 1; i <= N; ++i) 
        {
            cin >> B[i];
        }

        int S = 1;
        while (S < N) S <<= 1;
        vector<Node> tree(2 * S);
        auto makeNode = [&](int i) 
        {
            Node nd;
            if (A[i] + K < B[i]) { nd.f0 = 1; nd.cost0 = B[i]; } else { nd.f0 = 0; nd.cost0 = A[i]; }
            if (B[i] + K < A[i]) { nd.f1 = 0; nd.cost1 = A[i]; } else { nd.f1 = 1; nd.cost1 = B[i]; }
            return nd;
        };
        Node id;
        id.cost0 = 0;
        id.cost1 = 0;
        id.f0 = 0;
        id.f1 = 1;
        for (int i = 0; i < S; ++i) 
        {
            if (i < N) 
            {
                tree[S + i] = makeNode(i + 1);
            }
            else 
            {
                tree[S + i] = id;
            }
        }
        for (int i = S - 1; i >= 1; --i) 
        {
            Node &L = tree[2 * i];
            Node &R = tree[2 * i + 1];
            Node nd;
            if (L.f0 == 0) { nd.cost0 = L.cost0 + R.cost0; nd.f0 = R.f0; } else { nd.cost0 = L.cost0 + R.cost1; nd.f0 = R.f1; }
            if (L.f1 == 0) { nd.cost1 = L.cost1 + R.cost0; nd.f1 = R.f0; } else { nd.cost1 = L.cost1 + R.cost1; nd.f1 = R.f1; }
            tree[i] = nd;
        }
        int Q;
        cin >> Q;
        while (Q--) 
        {
            int t, p;
            ll x;
            cin >> t >> p >> x;
            if (t == 1) A[p] = x;
            else B[p] = x;
            int idx = S + p - 1;
            tree[idx] = makeNode(p);
            idx >>= 1;
            while (idx) 
            {
                Node &L = tree[2 * idx];
                Node &R = tree[2 * idx + 1];
                Node nd;
                if (L.f0 == 0) 
                { 
                    nd.cost0 = L.cost0 + R.cost0; nd.f0 = R.f0; 
                } 
                else 
                { 
                    nd.cost0 = L.cost0 + R.cost1; nd.f0 = R.f1; 
                }
                if (L.f1 == 0) 
                { 
                    nd.cost1 = L.cost1 + R.cost0; nd.f1 = R.f0; 
                } 
                else 
                { 
                    nd.cost1 = L.cost1 + R.cost1; nd.f1 = R.f1; 
                }
                tree[idx] = nd;
                idx >>= 1;
            }
            cout << tree[1].cost0 << '\n';
        }
    }
    return 0;
}