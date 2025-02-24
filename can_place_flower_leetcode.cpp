#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) 
        {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) 
                {
                flowerbed[i] = 1;
                --n;
                if (n <= 0) return true;
            }
        }
        
        return n <= 0;
    }
};

int main() {
    Solution solution;
    
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Input: flowerbed = [1, 0, 0, 0, 1], n = 1\n";
    cout << "Output: " << (solution.canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;
    
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << "Input: flowerbed = [1, 0, 0, 0, 1], n = 2\n";
    cout << "Output: " << (solution.canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;

    return 0;
}
