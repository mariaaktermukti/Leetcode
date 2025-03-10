#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        unordered_map<char, int> vowel_count; 
        int consonant_count = 0;
        int left = 0;
        long long valid_substrings = 0;

        for (int right = 0; right < n; ++right) {
            char ch = word[right];

            if (vowels.count(ch)) {
                vowel_count[ch]++;
            } else {
                consonant_count++;
            }

            while (consonant_count > k) {
                char left_char = word[left];

                if (vowels.count(left_char)) {
                    vowel_count[left_char]--;
                    if (vowel_count[left_char] == 0) {
                        vowel_count.erase(left_char);
                    }
                } else {
                    consonant_count--;
                }
                left++;
            }

            if (vowel_count.size() == 5 && consonant_count == k) {
                valid_substrings++;
            }
        }

        return valid_substrings;
    }
};

int main() {
    Solution solution;

    string word1 = "aeioqq";
    int k1 = 1;
    cout << "Output for word \"" << word1 << "\", k = " << k1 << ": " 
         << solution.countOfSubstrings(word1, k1) << endl;  

    string word2 = "aeiou";
    int k2 = 0;
    cout << "Output for word \"" << word2 << "\", k = " << k2 << ": " 
         << solution.countOfSubstrings(word2, k2) << endl; 

    string word3 = "ieaouqqieaouqq";
    int k3 = 1;
    cout << "Output for word \"" << word3 << "\", k = " << k3 << ": " 
         << solution.countOfSubstrings(word3, k3) << endl;  

    return 0;
}
