#include <iostream>
#include <vector>
using namespace std;

class BIT {
public:
    vector<int> tree;
    int size;

    BIT(int n) {
        size = n;
        tree.resize(n + 2, 0);
    }

    void update(int index, int val) {
        index++; 
        while (index <= size + 1) {
            tree[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> pos2(n);
    for (int i = 0; i < n; ++i) {
        pos2[nums2[i]] = i;
    }

    vector<int> pos_in_nums2(n);
    for (int i = 0; i < n; ++i) {
        pos_in_nums2[i] = pos2[nums1[i]];
    }

    vector<int> left_smaller(n, 0);
    BIT bit(n);
    for (int i = 0; i < n; ++i) {
        left_smaller[i] = bit.query(pos_in_nums2[i] - 1);
        bit.update(pos_in_nums2[i], 1);
    }

    vector<int> right_larger(n, 0);
    BIT bit2(n);
    for (int i = n - 1; i >= 0; --i) {
        right_larger[i] = bit2.query(n - 1) - bit2.query(pos_in_nums2[i]);
        bit2.update(pos_in_nums2[i], 1);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += (long long)left_smaller[i] * right_larger[i];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the length of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums2(n);

    cout << "Enter nums1 elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter nums2 elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    long long ans = goodTriplets(nums1, nums2);
    cout << "Number of good triplets: " << ans << endl;

    return 0;
}
