#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i) 
        {
            char first = words[i][0], last = words[i].back();
            if (vowels.count(first) && vowels.count(last)) 
            {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } 
            else 
            {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        vector<int> ans;
        for (const auto& query : queries) 
        {
            int li = query[0], ri = query[1];
            ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }

        return ans;
    }
};

int main() 
{
    Solution solution;
    vector<string> words1 = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries1 = {{0, 2}, {1, 4}, {1, 1}};

    vector<string> words2 = {"a", "e", "i"};
    vector<vector<int>> queries2 = {{0, 2}, {0, 1}, {2, 2}};

    vector<int> result1 = solution.vowelStrings(words1, queries1);
    vector<int> result2 = solution.vowelStrings(words2, queries2);

    for (int val : result1) 
    {
        printf("%d ", val);
    }
    printf("\n");

    for (int val : result2) 
    {
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}