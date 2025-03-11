#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (string word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());  // Sort the word
        anagramGroups[sortedWord].push_back(word);   // Group by sorted key
    }

    vector<vector<string>> result;
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
