#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> // Include this for reverse
using namespace std;

class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left <= right && s[left] == ' ') left++;
        while (left <= right && s[right] == ' ') right--;

        vector<string> words;
        string word;
        while (left <= right) 
        {
            char c = s[left];
            if (c != ' ') 
            {
                word += c;
            } 
            else if (!word.empty()) 
            {
                words.push_back(word);
                word.clear();
            }
            left++;
        }
        if (!word.empty()) 
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result;
        for (int i = 0; i < words.size(); i++) 
        {
            result += words[i];
            if (i < words.size() - 1) 
            {
                result += " ";
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";

    cout << "Input: \"" << s1 << "\"\n";
    cout << "Output: \"" << solution.reverseWords(s1) << "\"\n";

    cout << "Input: \"" << s2 << "\"\n";
    cout << "Output: \"" << solution.reverseWords(s2) << "\"\n";

    cout << "Input: \"" << s3 << "\"\n";
    cout << "Output: \"" << solution.reverseWords(s3) << "\"\n";

    return 0;
}
