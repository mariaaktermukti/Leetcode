#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];

            if (charToWord.count(ch)) {
                if (charToWord[ch] != words[i]) {
                    return false; 
                }
            } else {
                charToWord[ch] = words[i];
            }

            if (wordToChar.count(words[i])) {
                if (wordToChar[words[i]] != ch) {
                    return false; 
                }
            } else {
                wordToChar[words[i]] = ch;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    cout << boolalpha; 
    
    cout << solution.wordPattern("abba", "dog cat cat dog") << endl; 
    cout << solution.wordPattern("abba", "dog cat cat fish") << endl; 
    cout << solution.wordPattern("aaaa", "dog cat cat dog") << endl;  
    cout << solution.wordPattern("abc", "hello world hello") << endl; 

    return 0;
}
