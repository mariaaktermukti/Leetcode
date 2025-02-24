#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.length();
        if (n % 2 != 0) return false; 

        int openCount = 0, flexibleCount = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (locked[i] == '1') 
            {
                openCount += (s[i] == '(' ? 1 : -1);
            } 
            else 
            {
                flexibleCount++;
            }
            if (openCount + flexibleCount < 0) return false;
        }

        int closeCount = 0;
        flexibleCount = 0;
        for (int i = n - 1; i >= 0; --i) 
        {
            if (locked[i] == '1') 
            {
                closeCount += (s[i] == ')' ? 1 : -1);
            } 
            else 
            {
                flexibleCount++;
            }
            if (closeCount + flexibleCount < 0) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "))()))";
    string locked1 = "010100";
    cout << (solution.canBeValid(s1, locked1) ? "true" : "false") << endl;

    string s2 = "()()";
    string locked2 = "0000";
    cout << (solution.canBeValid(s2, locked2) ? "true" : "false") << endl;

    string s3 = ")";
    string locked3 = "0";
    cout << (solution.canBeValid(s3, locked3) ? "true" : "false") << endl;

    return 0;
}
