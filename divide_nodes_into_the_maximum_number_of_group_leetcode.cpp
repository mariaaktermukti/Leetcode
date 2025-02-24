#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>  
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, 0); 
        unordered_map<int, vector<int>> components;
        
        std::function<bool(int, int)> bfs_bipartite = [&](int start, int component_id) {
            queue<int> q;
            q.push(start);
            color[start] = 1;
            components[component_id].push_back(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                        components[component_id].push_back(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;  
                    }
                }
            }
            return true;
        };

        int component_id = 0;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                component_id++;
                if (!bfs_bipartite(i, component_id)) return -1;
            }
        }

        std::function<int(int)> bfs_max_depth = [&](int start) {
            queue<int> q;
            unordered_map<int, int> dist;
            q.push(start);
            dist[start] = 1;
            int max_depth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (dist.find(neighbor) == dist.end()) {
                        dist[neighbor] = dist[node] + 1;
                        max_depth = max(max_depth, dist[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return max_depth;
        };

        int max_groups = 0;
        for (auto it = components.begin(); it != components.end(); ++it) { 
            int best_depth = 0;
            for (int node : it->second) {
                best_depth = max(best_depth, bfs_max_depth(node));
            }
            max_groups += best_depth;
        }

        return max_groups;
    }
};

int main() {
    Solution solution;

    int n1 = 6;
    vector<vector<int>> edges1 = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
    cout << "Output (Test 1): " << solution.magnificentSets(n1, edges1) << endl; 

    int n2 = 3;
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,1}};
    cout << "Output (Test 2): " << solution.magnificentSets(n2, edges2) << endl; 

    int n3 = 5;
    vector<vector<int>> edges3 = {{1,2},{3,4}};
    cout << "Output (Test 3): " << solution.magnificentSets(n3, edges3) << endl; 

    return 0;
}
