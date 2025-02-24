#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string merged;
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;

        while (i < n || j < m) 
        {
            if (i < n) merged += word1[i++];
            if (j < m) merged += word2[j++];
        }

        return merged;
    }
};

int main() 
{
    Solution solution;

    string word1 = "abc", word2 = "pqr";
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    cout << "Output: " << solution.mergeAlternately(word1, word2) << endl;

    word1 = "ab", word2 = "pqrs";
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    cout << "Output: " << solution.mergeAlternately(word1, word2) << endl;

    word1 = "abcd", word2 = "pq";
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    cout << "Output: " << solution.mergeAlternately(word1, word2) << endl;

    return 0;
}
