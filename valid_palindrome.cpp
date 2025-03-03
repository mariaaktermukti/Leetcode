#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    string s1 = "A man, a plan, a canal: Panama";
    cout << (solution.isPalindrome(s1) ? "true" : "false") << endl;  

    string s2 = "race a car";
    cout << (solution.isPalindrome(s2) ? "true" : "false") << endl;  

    string s3 = " ";
    cout << (solution.isPalindrome(s3) ? "true" : "false") << endl;  

    return 0;
}
