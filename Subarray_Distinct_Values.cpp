#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto countAtMost = [&](int K) {
        unordered_map<int,int> freq;
        freq.reserve(K * 2);
        int distinct = 0;
        ll res = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (freq[a[right]] == 0) {
                distinct++;
            }
            freq[a[right]]++;
            while (distinct > K) {
                freq[a[left]]--;
                if (freq[a[left]] == 0) {
                    distinct--;
                }
                left++;
            }
            res += (right - left + 1);
        }
        return res;
    };

    ll answer = countAtMost(k);
    cout << answer << "\n";

    return 0;
}
