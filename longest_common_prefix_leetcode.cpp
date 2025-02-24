#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return ""; 
        
        string prefix = strs[0]; 
        
        for (int i = 1; i < strs.size(); ++i) 
        {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) 
            {
                j++; 
            }
            prefix = prefix.substr(0, j); 
            if (prefix.empty()) return "";
        }
        
        return prefix;
    }
};

int main() 
{
    Solution sol;
    
    vector<string> test1 = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(test1) << endl; 

    vector<string> test2 = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(test2) << endl; 

    vector<string> test3 = {"apple", "ape", "april"};
    cout << sol.longestCommonPrefix(test3) << endl; 

    return 0;
}
