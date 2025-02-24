#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) 
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) 
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i; 

        for (const auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        return find(source) == find(destination); 
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    cout << boolalpha << sol.validPath(3, edges1, 0, 2) << endl; 

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << boolalpha << sol.validPath(6, edges2, 0, 5) << endl; 

    return 0;
}
