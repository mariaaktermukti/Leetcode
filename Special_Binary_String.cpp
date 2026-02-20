#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        vector<string> chunks;
        int start = 0;
        int level = 0;

        for (int end = 0; end < s.size(); end++)
        {
            if (s[end] == '1')
                level++;
            else
                level--;

            if (level == 0)
            {
                chunks.push_back(
                    "1" + makeLargestSpecial(s.substr(start + 1, end - start - 1)) + "0");
                start = end + 1;
            }
        }

        sort(chunks.begin(), chunks.end(), greater<string>());

        string ans = "";
        for (auto &x : chunks)
            ans += x;

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.makeLargestSpecial(s) << endl;

    return 0;
}