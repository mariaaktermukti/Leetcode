#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);  
        unordered_set<string> directed_edges;  

        for (const auto& conn : connections) {
            int from = conn[0], to = conn[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
            directed_edges.insert(to_string(from) + "->" + to_string(to));  
        }

        int reorderCount = 0;
        vector<bool> visited(n, false);

        auto dfs = [&](int city, auto&& dfs_ref) -> void {
            visited[city] = true;
            for (int neighbor : adj[city]) {
                if (!visited[neighbor]) {
                    if (directed_edges.count(to_string(city) + "->" + to_string(neighbor))) {
                        reorderCount++;
                    }
                    dfs_ref(neighbor, dfs_ref);
                }
            }
        };

        dfs(0, dfs);  
        return reorderCount;
    }
};

int main() {
    Solution solution;

    int n1 = 6;
    vector<vector<int>> connections1 = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << "Output (Test 1): " << solution.minReorder(n1, connections1) << endl; 

    int n2 = 5;
    vector<vector<int>> connections2 = {{1,0},{1,2},{3,2},{3,4}};
    cout << "Output (Test 2): " << solution.minReorder(n2, connections2) << endl; 

    int n3 = 3;
    vector<vector<int>> connections3 = {{1,0},{2,0}};
    cout << "Output (Test 3): " << solution.minReorder(n3, connections3) << endl; 

    return 0;
}
