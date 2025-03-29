#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);  
        vector<int> indegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            int course = pre[0], prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; 
        while (!q.empty()) {
            int course = q.front(); q.pop();
            count++;

            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        return count == numCourses; 
    }
};

int main() {
    Solution sol;
    
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Output 1: " << sol.canFinish(numCourses1, prerequisites1) << endl; 

    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Output 2: " << sol.canFinish(numCourses2, prerequisites2) << endl; 

    return 0;
}
