#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        // Only start counting if num-1 is not in the set (ensures O(n) time complexity)
        if (!numSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.count(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }

            longest = max(longest, currentStreak);
        }
    }

    return longest;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
