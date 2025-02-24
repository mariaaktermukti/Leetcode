#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> reverseGraph(n, vector<int>());
        queue<int> q;

        for (int i = 0; i < n; ++i) 
        {
            outdegree[i] = graph[i].size(); 
            for (int j : graph[i]) 
            {
                reverseGraph[j].push_back(i);
            }
            if (outdegree[i] == 0) 
            {
                q.push(i); 
            }
        }

        vector<bool> safe(n, false);

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int parent : reverseGraph[node]) 
            {
                if (--outdegree[parent] == 0) 
                {
                    q.push(parent);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) 
        {
            if (safe[i]) 
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() 
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n);

    cout << "Enter the adjacency list for each node (end each list with -1):\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << "Node " << i << ": ";
        int neighbor;
        while (cin >> neighbor && neighbor != -1) 
        {
            graph[i].push_back(neighbor);
        }
    }

    Solution solution;
    vector<int> safeNodes = solution.eventualSafeNodes(graph);

    cout << "Safe nodes: ";
    for (int node : safeNodes) 
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
