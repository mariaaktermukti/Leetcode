#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.rbegin(), citations.rend()); 
        int h = 0;
        for (int i = 0; i < citations.size(); i++) 
        {
            if (citations[i] >= i + 1) 
            {
                h = i + 1;
            } 
            else 
            {
                break;
            }
        }
        return h;
    }
};

int main() {
    vector<int> citations1 = {3, 0, 6, 1, 5};
    vector<int> citations2 = {1, 3, 1};

    Solution solution;
    cout << "H-index (Example 1): " << solution.hIndex(citations1) << endl;
    cout << "H-index (Example 2): " << solution.hIndex(citations2) << endl;

    return 0;
}
