#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) 
    {
        string result;
        for (char c : s) 
        {
            if (c == '*') 
            {
                if (!result.empty()) result.pop_back(); 
            } 
            else 
            {
                result.push_back(c); 
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string test1 = "leet**cod*e";
    string test2 = "erase*****";
    string test3 = "a*b*c**";
    string test4 = "abc";

    cout << "Test 1: Input = \"" << test1 << "\", Output = \"" 
         << solution.removeStars(test1) << "\"" << endl;

    cout << "Test 2: Input = \"" << test2 << "\", Output = \"" 
         << solution.removeStars(test2) << "\"" << endl;

    cout << "Test 3: Input = \"" << test3 << "\", Output = \"" 
         << solution.removeStars(test3) << "\"" << endl;

    cout << "Test 4: Input = \"" << test4 << "\", Output = \"" 
         << solution.removeStars(test4) << "\"" << endl;

    return 0;
}
