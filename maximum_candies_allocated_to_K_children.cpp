#include <bits/stdc++.h>
using namespace std;

bool canDistribute(vector<int>& candies, long long k, long long candiesPerChild) {
    long long count = 0;
    for (int c : candies) {
        count += (c / candiesPerChild);
    }
    return count >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    long long low = 1, high = *max_element(candies.begin(), candies.end());
    long long result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canDistribute(candies, k, mid)) {
            result = mid; 
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return result;
}

int main() {
    vector<int> candies;
    long long k;
    int n;

    cout << "Enter number of candy piles: ";
    cin >> n;

    cout << "Enter candy piles: ";
    candies.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    cout << "Enter number of children: ";
    cin >> k;

    int result = maximumCandies(candies, k);

    cout << "Maximum candies each child can get: " << result << endl;

    return 0;
}
