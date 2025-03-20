#include <bits/stdc++.h>
using namespace std;

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> graph(n);

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }
    vector<int> component(n, -1); 
    vector<int> min_and(n, INT_MAX); 
    int component_id = 0;

    for (int i = 0; i < n; i++) {
        if (component[i] == -1) { 
            queue<int> q;
            q.push(i);
            component[i] = component_id;
            int comp_and = INT_MAX;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto& edge : graph[node]) {
                    int neighbor = edge.first;
                    int weight = edge.second;
                    comp_and &= weight;
                    if (component[neighbor] == -1) {
                        component[neighbor] = component_id;
                        q.push(neighbor);
                    }
                }
            }

            min_and[component_id] = comp_and;
            component_id++;
        }
    }

    vector<int> answer;
    for (auto& q : queries) {
        int si = q[0], ti = q[1];

        if (component[si] != component[ti]) {
            answer.push_back(-1);
        } else {
            answer.push_back(min_and[component[si]]);
        }
    }

    return answer;
}

int main() {
    int n, m, q;
    cin >> n >> m;
    
    vector<vector<int>> edges(m, vector<int>(3));
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> result = minimumCost(n, edges, queries);

    for (int ans : result) {
        cout << ans << endl;
    }

    return 0;
}
