#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);

            } else {
                st.push(stoi(token)); 
            }
        }
        
        return st.top(); 
    }
};

int main() {
    Solution sol;
    vector<string> tokens;

    tokens = {"2","1","+","3","*"};
    cout << "Output: " << sol.evalRPN(tokens) << endl; 

    tokens = {"4","13","5","/","+"};
    cout << "Output: " << sol.evalRPN(tokens) << endl;

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Output: " << sol.evalRPN(tokens) << endl; 

    return 0;
}
