#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;

        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinceCount = 0;

        for (int city = 0; city < n; ++city) {
            if (!visited[city]) {
                provinceCount++;
                dfs(city, isConnected, visited);
            }
        }

        return provinceCount;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Output (Test 1): " << solution.findCircleNum(isConnected1) << endl; 

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Output (Test 2): " << solution.findCircleNum(isConnected2) << endl; 

    return 0;
}
