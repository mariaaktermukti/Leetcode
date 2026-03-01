#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        unordered_set<ll> present;
        present.reserve(n * 2);
        for (ll x : a)
            present.insert(x);

        vector<ll> vals;
        vals.reserve(present.size());
        for (ll x : present)
            vals.push_back(x);
        sort(vals.begin(), vals.end());

        unordered_set<ll> finished;
        finished.reserve(vals.size() * 2);

        vector<ll> B;
        bool impossible = false;

        for (ll v : vals)
        {
            if (finished.find(v) != finished.end())
                continue;

            for (ll m = v; m <= k; m += v)
            {
                if (present.find(m) == present.end())
                {
                    impossible = true;
                    break;
                }
            }
            if (impossible)
                break;

            B.push_back(v);
            for (ll m = v; m <= k; m += v)
            {
                if (present.find(m) != present.end())
                    finished.insert(m);
            }
        }

        if (impossible)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << B.size() << '\n';
            for (size_t i = 0; i < B.size(); ++i)
            {
                if (i)
                    cout << ' ';
                cout << B[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
