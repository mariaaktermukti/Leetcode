#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generateHappyStrings(int n, string current, vector<string>& result) 
    {
        if (current.length() == n) 
        {
            result.push_back(current);
            return;
        }
        
        for (char c : {'a', 'b', 'c'}) 
        {
            if (current.empty() || current.back() != c) 
            {
                generateHappyStrings(n, current + c, result);
            }
        }
    }
    
    string getHappyString(int n, int k) 
    {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings);
        
        if (k > happyStrings.size()) 
        {
            return "";
        }
        
        return happyStrings[k - 1];
    }
};

int main() 
{
    int n, k;
    cout << "Enter values for n and k: ";
    cin >> n >> k;

    Solution solution;
    string result = solution.getHappyString(n, k);
    
    cout << "The " << k << "-th happy string of length " << n << " is: \"" << result << "\"" << endl;
    
    return 0;
}
