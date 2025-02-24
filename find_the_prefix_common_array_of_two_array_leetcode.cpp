#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_set<int> seenA, seenB;

        for (int i = 0; i < n; ++i) 
        {
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            int commonCount = 0;
            for (int num : seenA) 
            {
                if (seenB.count(num)) 
                {
                    ++commonCount;
                }
            }
            C[i] = commonCount;
        }

        return C;
    }
};

int main() {
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    Solution solution;
    
    vector<int> result = solution.findThePrefixCommonArray(A, B);

    cout << "Prefix common array: ";
    for (int val : result) 
    {
        cout << val << " ";
    }
    cout << endl;

    vector<int> A2 = {2, 3, 1};
    vector<int> B2 = {3, 1, 2};

    vector<int> result2 = solution.findThePrefixCommonArray(A2, B2);

    cout << "Prefix common array: ";
    for (int val : result2) 
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
