#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) 
    {
        if (n == 1) return "1";
        
        string result = "1"; 
        
        for (int i = 2; i <= n; ++i) 
        {
            string current = "";
            int count = 1; 
            
            for (int j = 1; j < result.size(); ++j) 
            {
                if (result[j] == result[j - 1]) 
                {
                    count++; 
                } 
                else 
                {
                    current += to_string(count) + result[j - 1];
                    count = 1; 
                }
            }
            current += to_string(count) + result.back();
            
            result = current;
        }
        
        return result;
    }
};

int main() 
{
    Solution solution;
    int n = 4;
    cout << "Count and Say for n = " << n << ": " << solution.countAndSay(n) << endl;

    n = 1;
    cout << "Count and Say for n = " << n << ": " << solution.countAndSay(n) << endl;

    n = 5;
    cout << "Count and Say for n = " << n << ": " << solution.countAndSay(n) << endl;

    return 0;
}
