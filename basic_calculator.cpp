#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;  
        int result = 0;  
        int sign = 1;    
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (isdigit(ch)) {  
                int num = 0;
                while (i < n && isdigit(s[i])) {  
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;  
                result += sign * num; 

            } else if (ch == '+') {
                sign = 1;  

            } else if (ch == '-') {
                sign = -1;  

            } else if (ch == '(') {
                st.push(result); 
                st.push(sign);    
                result = 0;       
                sign = 1;         

            } else if (ch == ')') {
                int prevSign = st.top(); st.pop();  
                int prevResult = st.top(); st.pop();  
                result = prevResult + prevSign * result;  

            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    string s1 = "1 + 1";
    cout << "Output: " << sol.calculate(s1) << endl;  

    string s2 = " 2-1 + 2 ";
    cout << "Output: " << sol.calculate(s2) << endl;  

    string s3 = "(1+(4+5+2)-3)+(6+8)";
    cout << "Output: " << sol.calculate(s3) << endl;  

    return 0;
}
