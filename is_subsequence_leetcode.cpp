#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) 
        {
            if (s[i] == t[j]) 
            {
                i++; 
            }
            j++; 
        }
        return i == s.length();
    }
};

int main() {
    Solution solution;

    string s1 = "abc", t1 = "ahbgdc";
    cout << "Is \"" << s1 << "\" a subsequence of \"" << t1 << "\"? ";
    cout << (solution.isSubsequence(s1, t1) ? "true" : "false") << endl;

    string s2 = "axc", t2 = "ahbgdc";
    cout << "Is \"" << s2 << "\" a subsequence of \"" << t2 << "\"? ";
    cout << (solution.isSubsequence(s2, t2) ? "true" : "false") << endl;

    string s3 = "", t3 = "ahbgdc";
    cout << "Is \"" << s3 << "\" a subsequence of \"" << t3 << "\"? ";
    cout << (solution.isSubsequence(s3, t3) ? "true" : "false") << endl;

    return 0;
}
