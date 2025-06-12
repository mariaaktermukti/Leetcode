#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> freq(n, 0);
    ll prefix = 0;
    ll answer = 0;

    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        prefix = (prefix + a) % n;
        if (prefix < 0) prefix += n;
        answer += freq[prefix];
        freq[prefix]++;
    }

    cout << answer << "\n";
    return 0;
}
