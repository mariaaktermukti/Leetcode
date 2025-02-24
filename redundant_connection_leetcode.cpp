#include <vector>
#include <iostream>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; 
        }

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        vector<int> result;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (!uf.unite(u, v)) {
                result = edge;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3}};
    vector<int> redundantEdge1 = sol.findRedundantConnection(edges1);
    cout << "Redundant Edge 1: [" << redundantEdge1[0] << ", " << redundantEdge1[1] << "]" << endl;

    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> redundantEdge2 = sol.findRedundantConnection(edges2);
    cout << "Redundant Edge 2: [" << redundantEdge2[0] << ", " << redundantEdge2[1] << "]" << endl;

    return 0;
}
