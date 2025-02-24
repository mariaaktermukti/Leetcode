#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size();
        int write = 0; 
        int read = 0;  

        while (read < n) 
        {
            char currentChar = chars[read];
            int count = 0;

            while (read < n && chars[read] == currentChar) 
            {
                read++;
                count++;
            }
            chars[write++] = currentChar;

            if (count > 1) 
            {
                string countStr = to_string(count);
                for (char c : countStr) 
                {
                    chars[write++] = c;
                }
            }
        }

        return write; 
    }
};

int main() {
    Solution solution;

    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength1 = solution.compress(chars1);
    cout << "Output: " << newLength1 << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength1; ++i) 
    {
        cout << chars1[i];
    }
    cout << endl;

    vector<char> chars2 = {'a'};
    int newLength2 = solution.compress(chars2);
    cout << "Output: " << newLength2 << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength2; ++i) 
    {
        cout << chars2[i];
    }
    cout << endl;

    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int newLength3 = solution.compress(chars3);
    cout << "Output: " << newLength3 << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength3; ++i) 
    {
        cout << chars3[i];
    }
    cout << endl;

    return 0;
}
