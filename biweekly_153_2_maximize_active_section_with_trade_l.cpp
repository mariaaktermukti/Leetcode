#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) 
    {
        int n = s.size();
        int totalOnes = 0;
        for (char ch : s) 
        {
            if (ch == '1')
                totalOnes++;
        }
        if(totalOnes == 0 || totalOnes == n)
            return totalOnes;  
        vector<pair<char,int>> runs;
        char curr = s[0];
        int count = 1;
        for (int i = 1; i < n; i++) 
        {
            if (s[i] == curr) 
            {
                count++;
            } 
            else 
            {
                runs.push_back({curr, count});
                curr = s[i];
                count = 1;
            }
        }
        runs.push_back({curr, count});
        
        int maxGain = 0;
        for (int i = 1; i < (int)runs.size() - 1; i++) 
        {
            if (runs[i].first == '1' && runs[i-1].first == '0' && runs[i+1].first == '0') 
            {
                int gain = runs[i-1].second + runs[i+1].second;
                if (gain > maxGain)
                    maxGain = gain;
            }
        }
        return totalOnes + maxGain;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cout << "Enter a binary string: ";
    cin >> s;
    
    Solution sol;
    int result = sol.maxActiveSectionsAfterTrade(s);
    cout << "Maximum number of active sections after trade: " << result << "\n";
    
    return 0;
}
