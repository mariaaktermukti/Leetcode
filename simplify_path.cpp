#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> st;
        stringstream ss(path);
        string token, result;

        while (getline(ss, token, '/')) 
        {
            if (token == "" || token == ".") 
                continue; 
            if (token == "..") 
            {
                if (!st.empty()) 
                    st.pop();
            } 
            else 
            {
                st.push(token); 
            }
        }

        while (!st.empty()) 
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    string path;
    cout << "Enter the Unix path: ";
    cin >> path;

    Solution sol;
    string simplifiedPath = sol.simplifyPath(path);

    cout << "Simplified Path: " << simplifiedPath << endl;
    return 0;
}
