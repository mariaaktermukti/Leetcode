#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int curr_tank = 0;
        int start = 0;
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total_tank += diff;
            curr_tank += diff;
            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }
        
        return total_tank >= 0 ? start : -1;
    }
};

int main() {
    Solution sol;
    
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    cout << "Example 1: " << sol.canCompleteCircuit(gas1, cost1) << endl; 

    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    cout << "Example 2: " << sol.canCompleteCircuit(gas2, cost2) << endl; 

    return 0;
}
