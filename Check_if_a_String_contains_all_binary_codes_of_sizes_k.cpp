#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        int total = 1 << k;

        if (s.length() - k + 1 < total)
            return false;

        unordered_set<string> st;

        for (int i = 0; i <= s.length() - k; i++)
        {
            st.insert(s.substr(i, k));
        }

        return st.size() == total;
    }
};

int main()
{
    string s;
    int k;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    if (obj.hasAllCodes(s, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}