#include <iostream>
#include <stack>
#include <string>

using namespace std;

string smallestNumber(string pattern) 
{
    string result;
    stack<int> st;
    int num = 1; 
    
    for (int i = 0; i <= pattern.size(); i++) 
    {
        st.push(num++); 
        
        if (i == pattern.size() || pattern[i] == 'I') 
        {
            while (!st.empty()) 
            {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    return result;
}

int main() {
    string pattern;
    cout << "Enter pattern (only 'I' and 'D'): ";
    cin >> pattern;
    
    string result = smallestNumber(pattern);
    
    cout << "Smallest lexicographical number: " << result << endl;
    
    return 0;
}
