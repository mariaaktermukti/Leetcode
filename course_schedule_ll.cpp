#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        vector<int> indegree(numCourses, 0); 
        
        for (auto& pre : prerequisites) {
            int course = pre[0], prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int course = q.front(); q.pop();
            order.push_back(course);

            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        return order.size() == numCourses ? order : vector<int>();
    }
};

int main() {
    Solution sol;

    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Output 1: ";
    for (int c : result1) cout << c << " ";
    cout << endl; 

    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Output 2: ";
    for (int c : result2) cout << c << " ";
    cout << endl;

    return 0;
}
