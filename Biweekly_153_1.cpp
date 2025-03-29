#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) 
        {
            int reversedIndex = 26 - (s[i] - 'a');
            sum = sum + reversedIndex * (i + 1);
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    cout << "Reverse Degree: " << sol.reverseDegree(s) << endl;
    
    return 0;
}
