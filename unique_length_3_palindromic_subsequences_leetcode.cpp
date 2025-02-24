#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurrence(26, -1), lastOccurrence(26, -1);
        unordered_set<string> uniquePalindromes;

        for (int i = 0; i < s.size(); ++i) 
        {
            int index = s[i] - 'a';
            if (firstOccurrence[index] == -1) 
            {
                firstOccurrence[index] = i;
            }
            lastOccurrence[index] = i;
        }

        for (int i = 0; i < 26; ++i) 
        {
            if (firstOccurrence[i] != -1 && firstOccurrence[i] < lastOccurrence[i]) 
            {
                unordered_set<char> middleChars;
                for (int j = firstOccurrence[i] + 1; j < lastOccurrence[i]; ++j) 
                {
                    middleChars.insert(s[j]);
                }
                for (char c : middleChars) 
                {
                    uniquePalindromes.insert(string(1, 'a' + i) + c + string(1, 'a' + i));
                }
            }
        }

        return uniquePalindromes.size();
    }
};

int main() 
{
    Solution solution;

    string s1 = "aabca";
    string s2 = "adc";
    string s3 = "bbcbaba";

    printf("%d\n", solution.countPalindromicSubsequence(s1));
    printf("%d\n", solution.countPalindromicSubsequence(s2));
    printf("%d\n", solution.countPalindromicSubsequence(s3)); 

    return 0;
}