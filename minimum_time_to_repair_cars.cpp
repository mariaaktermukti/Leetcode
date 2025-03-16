#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;
        for (int rank : ranks) {
            totalCars += sqrt(time / rank); 
            if (totalCars >= cars) return true; 
        }
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * 100 * cars * cars, ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, cars;
    cout << "Enter the number of mechanics: ";
    cin >> n;

    vector<int> ranks(n);
    cout << "Enter the ranks of mechanics: ";
    for (int i = 0; i < n; i++) {
        cin >> ranks[i];
    }

    cout << "Enter the number of cars: ";
    cin >> cars;

    Solution sol;
    long long result = sol.repairCars(ranks, cars);
    cout << "Minimum time required: " << result << endl;

    return 0;
}
