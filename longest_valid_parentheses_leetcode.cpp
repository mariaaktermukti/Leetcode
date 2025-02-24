#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        // Push -1 as the initial index to handle base case.
        st.push(-1);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // No matching '(' found, push current index as new base.
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    // Test cases
    Solution solution;
    
    // Example 1:
    string s1 = "(()";
    cout << "Input: " << s1 << "\nLongest Valid Parentheses Length: " << solution.longestValidParentheses(s1) << "\n\n";
    
    // Example 2:
    string s2 = ")()())";
    cout << "Input: " << s2 << "\nLongest Valid Parentheses Length: " << solution.longestValidParentheses(s2) << "\n\n";
    
    // Example 3:
    string s3 = "";
    cout << "Input: " << s3 << "\nLongest Valid Parentheses Length: " << solution.longestValidParentheses(s3) << "\n\n";
    
    return 0;
}
