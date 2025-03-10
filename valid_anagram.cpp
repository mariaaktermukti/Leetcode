#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    Solution solution;
    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::string s2 = "rat";
    std::string t2 = "car";

    std::cout << std::boolalpha; 
    std::cout << "Are \"" << s1 << "\" and \"" << t1 << "\" anagrams? " << solution.isAnagram(s1, t1) << std::endl;
    std::cout << "Are \"" << s2 << "\" and \"" << t2 << "\" anagrams? " << solution.isAnagram(s2, t2) << std::endl;

    return 0;
}
