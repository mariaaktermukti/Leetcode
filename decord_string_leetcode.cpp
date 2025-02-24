#include <iostream>
#include <string>
#include <stack>
#include <vector> 
using namespace std;

class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> string_stack;
        stack<int> count_stack;
        string current_string = "";
        int k = 0;

        for (char c : s) 
        {
            if (isdigit(c)) 
            {
                k = k * 10 + (c - '0');
            } 
            else if (c == '[') 
            {
                string_stack.push(current_string);
                count_stack.push(k);
                current_string = ""; 
                k = 0; 
            } 
            else if (c == ']') 
            {
                string decoded_string = current_string;
                int repeat_count = count_stack.top();
                count_stack.pop();

                current_string = string_stack.top();
                string_stack.pop();

                for (int i = 0; i < repeat_count; ++i) 
                {
                    current_string += decoded_string;
                }
            } 
            else
            {
                current_string += c;
            }
        }

        return current_string;
    }
};

int main() 
{
    Solution solution;

    vector<string> testCases = 
    {
        "3[a]2[bc]",       
        "3[a2[c]]",        
        "2[abc]3[cd]ef",   
        "10[a]",           
        "3[a10[bc]]",      
        "2[2[2[ab]]]c"     
    };

    for (size_t i = 0; i < testCases.size(); ++i) 
    {
        cout << "Test Case " << i + 1 << ": Input = \"" << testCases[i]
             << "\", Output = \"" << solution.decodeString(testCases[i]) << "\"" << endl;
    }

    return 0;
}
