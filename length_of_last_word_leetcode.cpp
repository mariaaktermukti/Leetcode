#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};

int main() {
    Solution sol;
    
    string s1 = "Hello World";
    cout << "Input: \"" << s1 << "\"\n";
    cout << "Output: " << sol.lengthOfLastWord(s1) << "\n\n"; 
    
    string s2 = "   fly me   to   the moon  ";
    cout << "Input: \"" << s2 << "\"\n";
    cout << "Output: " << sol.lengthOfLastWord(s2) << "\n\n"; 
    
    string s3 = "luffy is still joyboy";
    cout << "Input: \"" << s3 << "\"\n";
    cout << "Output: " << sol.lengthOfLastWord(s3) << "\n\n"; 
    
    return 0;
}
