#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if (k > s.size()) return false; 
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        int oddCount = 0;
        for (auto& entry : freq) 
        {
            if (entry.second % 2 != 0) 
            {
                oddCount++;
            }
        }
        return oddCount <= k;
    }
};

int main() 
{
    Solution solution;
    
    string s1 = "annabelle";
    int k1 = 2;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << (solution.canConstruct(s1, k1) ? "true" : "false") << endl << endl;
    
    string s2 = "leetcode";
    int k2 = 3;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << (solution.canConstruct(s2, k2) ? "true" : "false") << endl << endl;
    
    string s3 = "true";
    int k3 = 4;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << (solution.canConstruct(s3, k3) ? "true" : "false") << endl << endl;
    
    return 0;
}
