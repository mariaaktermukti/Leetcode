#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        vector<string> result; 

        for (int i = 0; i < words.size(); i++) 
        {
            for (int j = 0; j < words.size(); j++) 
            {
                if (i != j && words[j].find(words[i]) != string::npos) 
                {
                    result.push_back(words[i]);
                    break; 
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<string> words1 = {"mass", "as", "hero", "superhero"};
    vector<string> result1 = solution.stringMatching(words1);
    cout << "Example 1 Output: ";
    for (const string& word : result1) 
    {
        cout << word << " ";
    }
    cout << endl;

    vector<string> words2 = {"leetcode", "et", "code"};
    vector<string> result2 = solution.stringMatching(words2);
    cout << "Example 2 Output: ";
    for (const string& word : result2) 
    {
        cout << word << " ";
    }
    cout << endl;

    vector<string> words3 = {"blue", "green", "bu"};
    vector<string> result3 = solution.stringMatching(words3);
    cout << "Example 3 Output: ";
    for (const string& word : result3) 
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
