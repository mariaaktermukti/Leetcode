#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) 
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0, currentCount = 0;

        for (int i = 0; i < k; ++i) 
        {
            if (vowels.count(s[i])) 
            {
                currentCount++;
            }
        }
        maxCount = currentCount;

        for (int i = k; i < s.size(); ++i) 
        {
            if (vowels.count(s[i])) 
            {
                currentCount++; 
            }
            if (vowels.count(s[i - k])) 
            {
                currentCount--;
            }
            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};

int main() {
    Solution solution;

    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << solution.maxVowels(s1, k1) << endl;

    string s2 = "aeiou";
    int k2 = 2;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << solution.maxVowels(s2, k2) << endl;

    string s3 = "leetcode";
    int k3 = 3;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << solution.maxVowels(s3, k3) << endl;

    return 0;
}
