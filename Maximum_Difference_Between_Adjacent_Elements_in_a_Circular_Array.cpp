#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxi = 0;
    for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, abs(nums[i + 1] - nums[i]));
    }
    maxi = max(maxi, abs(nums[n - 1] - nums[0]));

    cout << maxi << "\n";
    return 0;
}
