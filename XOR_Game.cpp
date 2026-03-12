#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    vector<int> ct;
    vector<array<int, 2>> ch;
    Trie() : ct(1, 0), ch(1, {-1, -1}) {}
    void create()
    {
        ct.push_back(0);
        ch.push_back({-1, -1});
    }
    void insert(int x)
    {
        int node = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            ++ct[node];
            int b = (x >> bit) & 1;
            if (ch[node][b] == -1)
            {
                create();
                ch[node][b] = (int)ct.size() - 1;
            }
            node = ch[node][b];
        }
        ++ct[node];
    }
    void erase(int x)
    {
        int node = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            --ct[node];
            int b = (x >> bit) & 1;
            node = ch[node][b];
        }
        --ct[node];
    }

    array<int, 2> query_min(int x)
    {
        int node = 0, res = 0, val = 0;
        for (int bit = 30; bit >= 0; --bit)
        {
            int b = (x >> bit) & 1;
            if (ch[node][b] == -1 || ct[ch[node][b]] == 0)
            {
                val |= (1 ^ b) << bit;
                res |= 1 << bit;
                node = ch[node][1 ^ b];
            }
            else
            {
                val |= b << bit;
                node = ch[node][b];
            }
        }
        return {res, val};
    }
};

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Trie Ttrie;
        int X = 0;
        for (int v : a)
        {
            Ttrie.insert(v);
            X ^= v;
        }

        int mx1 = a[0], mx2 = (n > 1 ? a[1] : 0);
        if ((X ^ mx1) < (X ^ mx2))
            swap(mx1, mx2);
        for (int i = 2; i < n; ++i)
        {
            int val = X ^ a[i];
            if (val >= (X ^ mx1))
            {
                mx2 = mx1;
                mx1 = a[i];
            }
            else if (val >= (X ^ mx2))
                mx2 = a[i];
        }

        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1)
        {
            auto [mn, val] = Ttrie.query_min(X ^ a[j1]);
            int best = mn;
            if (val == mx1)
                best = min(best, X ^ mx2);
            else
                best = min(best, X ^ mx1);

            Ttrie.erase(val);
            Ttrie.insert(val ^ a[j1]);
            best = max(best, Ttrie.query_min(X ^ a[j1])[0]);
            Ttrie.erase(val ^ a[j1]);
            Ttrie.insert(val);

            ans = max(ans, best);
        }

        cout << ans << '\n';
    }
    return 0;
}