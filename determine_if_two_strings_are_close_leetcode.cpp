#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_set<char> set1, set2; 

        for (char c : word1) {
            freq1[c - 'a']++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        if (set1 != set2) return false;

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main() {
    Solution solution;

    string word1_1 = "abc";
    string word2_1 = "bca";
    cout << "Example 1: " << boolalpha << solution.closeStrings(word1_1, word2_1) << endl; // Output: true

    string word1_2 = "a";
    string word2_2 = "aa";
    cout << "Example 2: " << boolalpha << solution.closeStrings(word1_2, word2_2) << endl; // Output: false

    string word1_3 = "cabbba";
    string word2_3 = "abbccc";
    cout << "Example 3: " << boolalpha << solution.closeStrings(word1_3, word2_3) << endl; // Output: true

    string word1_4 = "abbzzca";
    string word2_4 = "babzzcz";
    cout << "Additional Test Case: " << boolalpha << solution.closeStrings(word1_4, word2_4) << endl; // Output: true

    return 0;
}
