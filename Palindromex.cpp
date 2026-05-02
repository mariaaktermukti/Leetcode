#include <bits/stdc++.h>
using namespace std;

vector<int> odd_pal(const vector<int> &a)
{
    int n = a.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; ++i)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && a[i - k] == a[i + k])
            ++k;
        d1[i] = k - 1;
        if (i + d1[i] > r)
        {
            l = i - d1[i];
            r = i + d1[i];
        }
    }
    return d1;
}

vector<int> even_pal(const vector<int> &a)
{
    int n = a.size();
    vector<int> d2(n);
    for (int i = 1, l = 0, r = -1; i < n; ++i)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && a[i - k - 1] == a[i + k])
            ++k;
        d2[i] = k;
        if (k > 0 && i + k - 1 > r)
        {
            l = i - k;
            r = i + k - 1;
        }
    }
    return d2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int N = 2 * n;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) cin >> a[i];

        vector<int> L(n, -1), R(n, -1);
        for (int i = 0; i < N; ++i)
        {
            int v = a[i];
            if (L[v] == -1) L[v] = i;
            else R[v] = i;
        }

        auto d1 = odd_pal(a);
        auto d2 = even_pal(a);

        vector<vector<pair<int, int>>> cents(n);
        for (int i = 0; i < n; ++i)
        {
            int sum = L[i] + R[i];
            if (sum % 2 == 0)
            {
                cents[i].push_back({0, sum / 2});
            }
            else
            {
                cents[i].push_back({1, (sum + 1) / 2});
            }
            cents[i].push_back({0, L[i]});
            cents[i].push_back({0, R[i]});
        }

        auto can = [&](int k) -> bool
        {
            if (k == 0) return true;
            vector<pair<int, int>> cur = cents[0];
            for (int i = 1; i < k; ++i)
            {
                vector<pair<int, int>> nxt;
                for (auto &c1 : cur)
                {
                    for (auto &c2 : cents[i])
                    {
                        if (c1 == c2)
                        {
                            nxt.push_back(c1);
                            break;
                        }
                    }
                }
                cur = nxt;
                if (cur.empty()) return false;
            }

            for (auto [type, pos] : cur)
            {
                int r_min = 0, r_max = INT_MAX;
                bool ok = true;
                for (int i = 0; i < k; ++i)
                {
                    int Li = L[i], Ri = R[i];
                    if (type == 0)
                    {
                        if (Li + Ri == 2 * pos)
                        {
                            r_min = max(r_min, pos - Li);
                            r_min = max(r_min, Ri - pos);
                        }
                        else if (Li == pos)
                        { 
                            r_max = min(r_max, Ri - pos - 1);
                        }
                        else if (Ri == pos)
                        {
                            r_max = min(r_max, pos - Li - 1);
                        }
                        else
                        {
                            ok = false;
                            break;
                        }
                    }
                    else
                    { 
                        if (Li + Ri == 2 * pos - 1)
                        {
                            r_min = max(r_min, pos - Li);
                            r_min = max(r_min, Ri - pos + 1);
                        }
                        else
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) continue;
                if (type == 0)
                {
                    if (r_min <= min(r_max, d1[pos])) return true;
                }
                else
                {
                    if (r_min <= d2[pos]) return true;
                }
            }
            return false;
        };

        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << endl;
    }
    return 0;
}