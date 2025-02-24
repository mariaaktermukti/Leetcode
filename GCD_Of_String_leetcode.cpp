#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
       
        if (str1 + str2 != str2 + str1) 
        {
            return ""; 
        }
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength); 
    }

private:
    int gcd(int a, int b)
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution solution;

    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "Test Case 1: " << solution.gcdOfStrings(str1, str2) << endl; 

    str1 = "ABABAB";
    str2 = "ABAB";
    cout << "Test Case 2: " << solution.gcdOfStrings(str1, str2) << endl; 

    str1 = "LEET";
    str2 = "CODE";
    cout << "Test Case 3: " << solution.gcdOfStrings(str1, str2) << endl; 

    return 0;
}
