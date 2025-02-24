#include <iostream>
#include <bitset>

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2); 
        int x = 0;
        int setBitsUsed = 0;

        for (int i = 31; i >= 0 && setBitsUsed < setBitsNum2; --i) 
        {
            if (num1 & (1 << i)) 
            {
                x |= (1 << i);
                setBitsUsed++;
            }
        }

        for (int i = 0; i < 32 && setBitsUsed < setBitsNum2; ++i) 
        {
            if (!(x & (1 << i))) 
            { 
                x |= (1 << i);
                setBitsUsed++;
            }
        }

        return x;
    }
};

int main() {
    Solution sol;
    int num1 = 3, num2 = 5;
    int result = sol.minimizeXor(num1, num2);
    std::cout << "Result: " << result << std::endl; 
    return 0;
}
