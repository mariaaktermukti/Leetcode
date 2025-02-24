#include <iostream>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    string reverseVowels(string s) 
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;

        while (left < right) 
        {
            while (left < right && vowels.find(s[left]) == vowels.end()) 
            {
                left++;
            }
            while (left < right && vowels.find(s[right]) == vowels.end()) 
            {
                right--;
            }
            if (left < right) 
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    Solution solution;

    string s1 = "IceCreAm";
    string s2 = "leetcode";

    cout << "Input: " << s1 << "\n";
    cout << "Output: " << solution.reverseVowels(s1) << "\n";

    cout << "Input: " << s2 << "\n";
    cout << "Output: " << solution.reverseVowels(s2) << "\n";

    return 0;
}
