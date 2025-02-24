#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right && s[left] == s[right]) {
            char currentChar = s[left];
            while (left <= right && s[left] == currentChar) {
                left++;
            }
            while (left <= right && s[right] == currentChar) {
                right--;
            }
        }

        return right - left + 1;
    }
};

int main() {
    Solution solution;

    string s1 = "abaacbcbb";
    cout << "Input: " << s1 << "\nOutput: " << solution.minimumLength(s1) << "\n\n";


    string s2 = "aa";
    cout << "Input: " << s2 << "\nOutput: " << solution.minimumLength(s2) << "\n\n";

    string s3 = "a";
    cout << "Input: " << s3 << "\nOutput: " << solution.minimumLength(s3) << "\n\n";

    string s4 = "abcddcba";
    cout << "Input: " << s4 << "\nOutput: " << solution.minimumLength(s4) << "\n\n";

    string s5 = "aabccbaa";
    cout << "Input: " << s5 << "\nOutput: " << solution.minimumLength(s5) << "\n\n";

    return 0;
}