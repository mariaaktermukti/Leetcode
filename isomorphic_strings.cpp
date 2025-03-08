#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t, t_to_s;

        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i], char_t = t[i];

            if (s_to_t.count(char_s) && s_to_t[char_s] != char_t) {
                return false;
            }

            if (t_to_s.count(char_t) && t_to_s[char_t] != char_s) {
                return false;
            }

            s_to_t[char_s] = char_t;
            t_to_s[char_t] = char_s;
        }
        
        return true;
    }
};

int main() {
    Solution solution;

    cout << boolalpha; 
    cout << "Test Case 1: " << solution.isIsomorphic("egg", "add") << endl;   
    cout << "Test Case 2: " << solution.isIsomorphic("foo", "bar") << endl;    
    cout << "Test Case 3: " << solution.isIsomorphic("paper", "title") << endl;
    cout << "Test Case 4: " << solution.isIsomorphic("badc", "baba") << endl; 

    return 0;
}
