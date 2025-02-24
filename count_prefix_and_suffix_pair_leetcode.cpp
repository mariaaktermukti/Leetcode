#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        auto isPrefixAndSuffix = [](const string& str1, const string& str2) 
        {
            return str2.substr(0, str1.size()) == str1 && 
                   str2.substr(str2.size() - str1.size()) == str1;
        };
        
        int count = 0;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (isPrefixAndSuffix(words[i], words[j])) 
                {
                    ++count;
                }
            }
        }
        
        return count;
    }
};

int main() 
{
    Solution solution;
    
    vector<string> words1 = {"a", "aba", "ababa", "aa"};
    cout << "Example 1 Output: " << solution.countPrefixSuffixPairs(words1) << endl;
    
    vector<string> words2 = {"pa", "papa", "ma", "mama"};
    cout << "Example 2 Output: " << solution.countPrefixSuffixPairs(words2) << endl;
    
    vector<string> words3 = {"abab", "ab"};
    cout << "Example 3 Output: " << solution.countPrefixSuffixPairs(words3) << endl;

    return 0;
}
