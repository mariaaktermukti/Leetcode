#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> firstOccurrence(26, -1), lastOccurrence(26, -1);
        unordered_set<string> uniquePalindromes;

        for (int i = 0; i < s.size(); ++i) 
        {
            int index = s[i] - 'a';
            if (firstOccurrence[index] == -1) 
            {
                firstOccurrence[index] = i;
            }
            lastOccurrence[index] = i;
        }

        for (int i = 0; i < 26; ++i) 
        {
            if (firstOccurrence[i] != -1 && firstOccurrence[i] < lastOccurrence[i]) 
            {
                unordered_set<char> middleChars;
                for (int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; ++j) 
                {
                    middleChars.insert(s[j]);
                }
                for (char c : middleChars) 
                {
                    uniquePalindromes.insert(string(1, 'a' + i) + c + string(1, 'a' + i));
                }
            }
        }

        return uniquePalindromes.size();
    }

    int largestAltitude(vector<int>& gain) 
    {
        int maxAltitude = 0, currentAltitude = 0;
        for (int g : gain) 
        {
            currentAltitude += g;
            maxAltitude = max(maxAltitude, currentAltitude);
        }
        return maxAltitude;
    }

    int pivotIndex(vector<int>& nums) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) 
        {
            if (leftSum == totalSum - leftSum - nums[i]) 
            {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {
    Solution solution;

    string s1 = "aabca";
    string s2 = "adc";
    string s3 = "bbcbaba";

    printf("%d\n", solution.countPalindromicSubsequence(s1));
    printf("%d\n", solution.countPalindromicSubsequence(s2)); 
    printf("%d\n", solution.countPalindromicSubsequence(s3)); 

    vector<int> gain1 = {-5, 1, 5, 0, -7};
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};

    printf("%d\n", solution.largestAltitude(gain1)); 
    printf("%d\n", solution.largestAltitude(gain2)); 

    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {2, 1, -1};

    printf("%d\n", solution.pivotIndex(nums1));
    printf("%d\n", solution.pivotIndex(nums2)); 
    printf("%d\n", solution.pivotIndex(nums3)); 

    return 0;
}
