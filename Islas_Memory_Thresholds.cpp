#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static const int MAXN = 200000 + 5;
static const int B = 512;
static const ll INF = 1000000001LL;

int T;
int n, q;
int a[MAXN];
ll pref[MAXN];

int L[MAXN], R[MAXN], X[MAXN];
int idx[MAXN];

int jump[B + 3][MAXN];

void solve()
{
    cin >> n >> q;

    vector<int> values;
    values.clear();

    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> L[i] >> R[i] >> X[i];
        values.push_back(X[i]);
    }

    values.push_back(0);
    values.push_back(1000000008);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    for (int i = 1; i <= q; i++)
    {
        idx[i] = lower_bound(values.begin(), values.end(), X[i]) - values.begin();
    }

    for (int len = 1; len <= B; len++)
    {
        int k = 0;
        for (int j = n - len; j >= 0; j--)
        {
            ll blockSum = pref[j + len] - pref[j];
            while (k < (int)values.size() && values[k] <= min(blockSum, INF))
            {
                jump[len][k] = j + 1;
                k++;
            }
        }
    }

    for (int qi = 1; qi <= q; qi++)
    {
        int l = L[qi];
        int r = R[qi];
        int x = X[qi];

        int clearCount = 0;

        for (int len = 1; len <= B; len++)
        {
            if (jump[len][idx[qi]] >= l)
            {
                int times = min(r - l + 1, jump[len][idx[qi]] - l + len) / len;
                clearCount += times;
                l += times * len;
            }
        }

        l--;

        while (true)
        {
            ll remaining = pref[r] - pref[l];
            if (remaining < x)
            {
                cout << clearCount << " " << remaining << "\n";
                break;
            }

            clearCount++;

            ll need = pref[l] + x;
            int lo = l - 1, hi = n + 1;

            while (lo + 1 < hi)
            {
                int mid = (lo + hi) >> 1;
                if (pref[mid] < need)
                    lo = mid;
                else
                    hi = mid;
            }
            l = hi;
        }
    }

    for (int i = 0; i <= max(n, (int)values.size()) + 2; i++)
        pref[i] = 0;

    for (int i = 0; i <= B + 2; i++)
        for (int j = 0; j <= max(n, (int)values.size()) + 2; j++)
            jump[i][j] = 0;
}

int main()
{
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
