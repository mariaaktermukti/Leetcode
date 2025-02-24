#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        const int INF = numeric_limits<int>::max();
        vector<int> bobTime(n, INF);
        vector<int> parent(n, -1);
        
        queue<int> q;
        q.push(0);
        parent[0] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(nxt == parent[cur])
                    continue;
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
        
        int cur = bob;
        int t = 0;
        while (true) {
            bobTime[cur] = t;
            if(cur == 0)
                break;
            cur = parent[cur];
            t++;
        }

        int ans = -INF;
        function<void(int, int, int, int)> dfsTotal = [&](int node, int par, int time, int currSum) {
            int add = 0;
            if (time < bobTime[node])
                add = amount[node];
            else if (time == bobTime[node])
                add = amount[node] / 2;
            else
                add = 0;
            int newSum = currSum + add;

            if (node != 0 && adj[node].size() == 1) {
                ans = max(ans, newSum);
            }
            
            for (int nxt : adj[node]) {
                if (nxt == par) continue;
                dfsTotal(nxt, node, time + 1, newSum);
            }
        };
        
        dfsTotal(0, -1, 0, 0);
        return ans;
    }
};

int main() {
    {
        vector<vector<int>> edges = {{0,1}, {1,2}, {1,3}, {3,4}};
        int bob = 3;
        vector<int> amount = {-2, 4, 2, -4, 6};
        Solution sol;
        int result = sol.mostProfitablePath(edges, bob, amount);
        cout << "Test case 1: Maximum net income for Alice: " << result << "\n"; 
    }
    
    {
        vector<vector<int>> edges = {{0,1}};
        int bob = 1;
        vector<int> amount = {-7280, 2350};
        Solution sol;
        int result = sol.mostProfitablePath(edges, bob, amount);
        cout << "Test case 2: Maximum net income for Alice: " << result << "\n"; 
    }
    
    return 0;
}
