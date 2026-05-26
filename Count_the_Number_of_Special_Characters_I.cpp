#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {

        unordered_set<char> s;

        for (char ch : word)
        {
            s.insert(ch);
        }

        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (s.count(ch) && s.count(toupper(ch)))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    string word;
    cin >> word;

    Solution obj;
    cout << obj.numberOfSpecialChars(word) << endl;

    return 0;
}