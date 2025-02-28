#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();
        
        while (i < n) {
            int lineLength = 0, j = i;
            
            while (j < n && (lineLength + words[j].size() + (j - i)) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength; 
            string line = words[i];

            if (j == n || numWords == 1) {
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line.append(maxWidth - line.size(), ' '); 
            } 
            else {
                int spaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i + 1; k < j; k++) {
                    line.append(spaces + (extraSpaces-- > 0 ? 1 : 0), ' '); 
                    line += words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    
    vector<string> result = solution.fullJustify(words, maxWidth);
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}
