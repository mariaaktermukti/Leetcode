#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);
    
    for (const auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].emplace_back(v, time);
        graph[v].emplace_back(u, time);
    }
    vector<long long> shortest_time(n, LLONG_MAX);
    vector<long long> path_count(n, 0);
    shortest_time[0] = 0;
    path_count[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [curr_time, u] = pq.top();
        pq.pop();

        if (curr_time > shortest_time[u]) continue;

        for (auto [v, time] : graph[u]) {
            long long new_time = curr_time + time;

            if (new_time < shortest_time[v]) {
                shortest_time[v] = new_time;
                path_count[v] = path_count[u];
                pq.push({new_time, v});
            } 
            else if (new_time == shortest_time[v]) {
                path_count[v] = (path_count[v] + path_count[u]) % MOD;
            }
        }
    }

    return path_count[n-1];
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    cout << countPaths(n, roads) << endl;
    return 0;
}
