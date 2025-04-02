#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> result;
    if (nums1.empty() || nums2.empty() || k == 0) return result;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
    for (int i = 0; i < nums1.size() && i < k; i++) {
        minHeap.push(make_tuple(nums1[i] + nums2[0], i, 0));
    }
    while (k-- > 0 && !minHeap.empty()) {
        auto [sum, i, j] = minHeap.top();
        minHeap.pop();

        result.push_back({nums1[i], nums2[j]});
        if (j + 1 < nums2.size()) {
            minHeap.push(make_tuple(nums1[i] + nums2[j + 1], i, j + 1));
        }
    }

    return result;
}
int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<pair<int, int>> result = kSmallestPairs(nums1, nums2, k);

    cout << "The " << k << " pairs with the smallest sums are:\n";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
