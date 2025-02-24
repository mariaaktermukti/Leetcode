#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canPartition(string num, int target, int index, int currentSum) 
    {
        if (index == num.size()) 
        {
            return currentSum == target; 
        }

        int sum = 0;
        for (int j = index; j < num.size(); ++j) 
        {
            sum = sum * 10 + (num[j] - '0'); 
            if (sum + currentSum > target) break; 
            if (canPartition(num, target, j + 1, sum + currentSum)) return true;
        }

        return false;
    }

    int punishmentNumber(int n) 
    {
        int punishment = 0;
        
        for (int i = 1; i <= n; ++i) 
        {
            int square = i * i;
            string squareStr = to_string(square);
            
            if (canPartition(squareStr, i, 0, 0)) 
            {
                punishment += square;
            }
        }

        return punishment;
    }
};

int main() {
    Solution sol;
    
    cout << sol.punishmentNumber(10) << endl; 
    cout << sol.punishmentNumber(37) << endl; 
    
    return 0;
}
