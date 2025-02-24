#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        unordered_set<string> s(nums.begin(), nums.end());
        
        for (int i = 0; i < (1 << n); ++i) 
        {
            bitset<16> bs(i); 
            string candidate = bs.to_string().substr(16 - n); 
            if (s.find(candidate) == s.end()) 
            {
                return candidate;
            }
        }
        return ""; 
    }
};

int main() {
    vector<vector<string>> testCases = 
    {
        {"01","10"},
        {"00","01"},
        {"111","011","001"}
    };

    Solution sol;
    for (auto& nums : testCases) 
    {
        string res = sol.findDifferentBinaryString(nums);
        cout << "For input: ";
        for (auto &s : nums) 
        {
            cout << s << " ";
        }
        cout << "\nOutput: " << res << "\n\n";
    }
    
    return 0;
}
