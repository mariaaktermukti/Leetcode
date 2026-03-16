 #include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>
using namespace std;
const long long INF = 1e18;

void solve() 
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    int total_zeros = 0;
    for (int i = 0; i < m; ++i) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u; 
        --v;
        edges.emplace_back(u, v, w);
        if (w == 0) 
        {
            total_zeros++;
        }
    }
    vector<long long> block_cost(1 << n, INF);

    for (int mask = 1; mask < (1 << n); ++mask) 
    {
        vector<int> nodes;
        for (int i = 0; i < n; ++i) 
        {
            if ((mask >> i) & 1) 
            {
                nodes.push_back(i);
            }
        }
        int num_nodes = nodes.size();

        vector<pair<int, int>> sub_edges_endpoints;
        int sub_zeros = 0;
        
        for (const auto& edge : edges) 
        {
            int u, v, w;
            tie(u, v, w) = edge;
            bool u_in = (mask >> u) & 1;
            bool v_in = (mask >> v) & 1;
            if (u_in && v_in)
             {
                sub_edges_endpoints.push_back({u, v});
                if (w == 0) 
                {
                    sub_zeros++;
                }
            }
        }
        
        int num_sub_edges = sub_edges_endpoints.size();
        if (num_sub_edges != num_nodes - 1) 
        {
            continue;
        }
        
        if (num_nodes <= 1) 
        {
             block_cost[mask] = (long long)num_sub_edges - 2LL * sub_zeros;
             continue;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : sub_edges_endpoints) 
        {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }

        vector<bool> visited(n, false);
        vector<int> q;
        q.push_back(nodes[0]);
        visited[nodes[0]] = true;
        int head = 0;
        int visited_count = 1;
        
        while(head < q.size())
        {
            int u = q[head++];
            for(int v : adj[u])
            {
                if(!visited[v])
                { 
                    visited[v] = true;
                    q.push_back(v);
                    visited_count++;
                }
            }
        }

        if (visited_count == num_nodes) 
        { 
            block_cost[mask] = (long long)num_sub_edges - 2LL * sub_zeros;
        }
    }

    vector<long long> dp(1 << n, INF);
    dp[0] = 0;
    
    for (int mask = 1; mask < (1 << n); ++mask) 
    {
        int pivot = mask & -mask; 
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) 
        {
            if ((submask & pivot) == pivot) 
            { 
                if (block_cost[submask] != INF) 
                {
                    int rem_mask = mask ^ submask;
                    if (dp[rem_mask] != INF) 
                    {
                        dp[mask] = min(dp[mask], dp[rem_mask] + block_cost[submask]);
                    }
                }
            }
        }
    }
    
    long long final_dp_val = dp[(1 << n) - 1];
    cout << total_zeros + final_dp_val << endl;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}