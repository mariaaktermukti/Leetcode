#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> romanMap = 
        {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (int i = s.size() - 1; i >= 0; i--) 
        {
            int currentValue = romanMap[s[i]];
            if (currentValue < prevValue) 
            {
                total -= currentValue;
            } 
            else 
            {
                total += currentValue;
            }
            prevValue = currentValue;
        }

        return total;
    }
};

int main() {
    Solution solution;

    string test1 = "III";
    string test2 = "LVIII";
    string test3 = "MCMXCIV";

    cout << "Input: " << test1 << "\nOutput: " << solution.romanToInt(test1) << endl;
    cout << "Input: " << test2 << "\nOutput: " << solution.romanToInt(test2) << endl;
    cout << "Input: " << test3 << "\nOutput: " << solution.romanToInt(test3) << endl;

    return 0;
}