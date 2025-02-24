#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        
        int wordLen = words[0].size();
        int wordCount = words.size();
        int sLen = s.size();
        
        unordered_map<string, int> wordFreq;
        for(const string &word : words)
            wordFreq[word]++;
        
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> currFreq;
            for (int j = i; j <= sLen - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordFreq.find(word) != wordFreq.end()) {
                    currFreq[word]++;
                    count++;
                    while (currFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        currFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    currFreq.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;

    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring(s1, words1);
    cout << "Example 1 Output: ";
    for (int idx : result1)
        cout << idx << " ";
    cout << endl;
    
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = sol.findSubstring(s2, words2);
    cout << "Example 2 Output: ";
    for (int idx : result2)
        cout << idx << " ";
    cout << endl;

    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> result3 = sol.findSubstring(s3, words3);
    cout << "Example 3 Output: ";
    for (int idx : result3)
        cout << idx << " ";
    cout << endl;
    
    return 0;
}
