#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    long long maxVal = 0;

    vector<int> prefixMax(n, 0);
    prefixMax[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
    }

    vector<int> suffixMax(n, 0);
    suffixMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }

    for (int j = 1; j < n - 1; j++) {
        long long max_i = prefixMax[j - 1];  
        long long max_k = suffixMax[j + 1]; 
        long long tripletValue = (max_i - nums[j]) * max_k;
        maxVal = max(maxVal, tripletValue);
    }
    
    return maxVal;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }
    
    cout << maximumTripletValue(nums) << endl;
    return 0;
}
