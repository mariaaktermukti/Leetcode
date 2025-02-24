#include <vector>
#include <cstdio>  
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
    
        vector<int> original(n, 0); 
        
        for (int i = 1; i < n; ++i) {
            original[i] = original[i - 1] ^ derived[i - 1]; 
        }
        
        for (int i = 0; i < n; ++i) {
            if ((original[i] ^ original[(i + 1) % n]) != derived[i]) {
                return false; 
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    vector<int> derived1 = {1, 1, 0};
    vector<int> derived2 = {1, 1};
    vector<int> derived3 = {1, 0};
    
    if (solution.doesValidArrayExist(derived1)) {
        printf("Test case 1: true\n");
    } else {
        printf("Test case 1: false\n");
    }

    if (solution.doesValidArrayExist(derived2)) {
        printf("Test case 2: true\n");
    } else {
        printf("Test case 2: false\n");
    }

    if (solution.doesValidArrayExist(derived3)) {
        printf("Test case 3: true\n");
    } else {
        printf("Test case 3: false\n");
    }
    
    return 0;
}
