#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {

        size_t starPos = p.find('*');

        string prefix = p.substr(0, starPos);
        string suffix = p.substr(starPos + 1);

        size_t prefixPos = s.find(prefix);
        if (prefixPos == string::npos) {
            return false;
        }

        size_t suffixPos = s.find(suffix, prefixPos + prefix.length());
        return suffixPos != string::npos && suffixPos >= prefixPos + prefix.length();
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "leetcode", p1 = "ee*e";
    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s1, p1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "car", p2 = "c*v";
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s2, p2) ? "true" : "false") << endl;

    // Example 3
    string s3 = "luck", p3 = "u*";
    cout << "Input: s = \"" << s3 << "\", p = \"" << p3 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s3, p3) ? "true" : "false") << endl;

    // Edge Case 1: Empty Prefix
    string s4 = "abcde", p4 = "*de";
    cout << "Input: s = \"" << s4 << "\", p = \"" << p4 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s4, p4) ? "true" : "false") << endl;

    // Edge Case 2: Empty Suffix
    string s5 = "abcde", p5 = "ab*";
    cout << "Input: s = \"" << s5 << "\", p = \"" << p5 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s5, p5) ? "true" : "false") << endl;

    // Edge Case 3: Match Entire String
    string s6 = "abcde", p6 = "*";
    cout << "Input: s = \"" << s6 << "\", p = \"" << p6 << "\"" << endl;
    cout << "Output: " << (solution.hasMatch(s6, p6) ? "true" : "false") << endl;

    return 0;
}