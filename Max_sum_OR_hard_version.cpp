#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> build(ll l, ll r)
{
    if (l > r)
        return {};
    if (l == r)
        return {l};
    int msb = -1;
    for (int b = 60; b >= 0; --b)
    {
        if (((l >> b) & 1LL) != ((r >> b) & 1LL))
        {
            msb = b;
            break;
        }
    }
    ll t = (r >> msb) << msb;
    ll p = 2 * t - 1;
    ll left_len = t - l;
    ll right_len = r - t + 1;
    if (left_len <= right_len)
    {
        vector<ll> leftSeg;
        ll upto = p - l;
        for (ll x = l; x <= upto; ++x)
            leftSeg.push_back(x);
        reverse(leftSeg.begin(), leftSeg.end());
        vector<ll> suf = build(p - l + 1, r);
        leftSeg.insert(leftSeg.end(), suf.begin(), suf.end());
        return leftSeg;
    }
    else
    {
        vector<ll> rightSeg;
        ll from = p - r;
        for (ll x = from; x <= r; ++x)
            rightSeg.push_back(x);
        reverse(rightSeg.begin(), rightSeg.end());
        vector<ll> pref = build(l, p - r - 1);
        pref.insert(pref.end(), rightSeg.begin(), rightSeg.end());
        return pref;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    if (!(cin >> tc))
        return 0;
    while (tc--)
    {
        ll l, r;
        cin >> l >> r;
        vector<ll> a = build(l, r);
        long long n = r - l + 1;
        unsigned long long sum = 0;
        for (long long i = 0; i < n; ++i)
        {
            unsigned long long ai = (unsigned long long)a[i];
            unsigned long long bi = (unsigned long long)(l + i);
            sum += (ai | bi);
        }
        cout << sum << '\n';
        for (ll i = 0; i < n; ++i)
        {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
