#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        ll r;
        string s;
        cin >> n >> r >> s;
        vector<int> pos;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != 'I')
                pos.push_back(i);
        }

        if (pos.empty())
        {
            cout << n * r - 1 << "\n";
            continue;
        }

        ll score = 0;
        score += pos[0];

        for (size_t i = 0; i + 1 < pos.size(); ++i)
        {
            int a = pos[i];
            int b = pos[i + 1];
            int gap = b - a - 1;

            if (gap == 0)
            {
                score += (s[a] == s[b]) ? 1 : 0;
            }
            else
            {
                score += (s[a] == s[b]) ? gap + 1 : gap;
            }
        }

        score += (n - 1 - pos.back());

        ll total;
        if (r == 1)
        {
            total = score;
        }
        else
        {
            total = score * r;
            if (s[pos.front()] == s[pos.back()])
                total += r - 1;
        }

        cout << total << "\n";
    }

    return 0;
}