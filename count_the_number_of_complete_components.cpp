#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& component) {
    visited[node] = true;
    component.insert(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

bool isComplete(const unordered_set<int>& component, const vector<vector<int>>& adj) {
    for (int u : component) {
        for (int v : component) {
            if (u != v && std::find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
                return false;
            }
        }
    }
    return true;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    int completeComponents = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            unordered_set<int> component;
            dfs(i, adj, visited, component);

            if (isComplete(component, adj)) {
                ++completeComponents;
            }
        }
    }

    return completeComponents;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter edges (u v format):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = countCompleteComponents(n, edges);
    cout << "Number of complete connected components: " << result << endl;

    return 0;
}
