#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letterCount(26, 0);
        
        for (char c : magazine) {
            letterCount[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (letterCount[c - 'a'] == 0) {
                return false;  
            }
            letterCount[c - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    cout << boolalpha; 
    cout << "Test Case 1: " << solution.canConstruct("a", "b") << endl;   
    cout << "Test Case 2: " << solution.canConstruct("aa", "ab") << endl; 
    cout << "Test Case 3: " << solution.canConstruct("aa", "aab") << endl; 

    return 0;
}
