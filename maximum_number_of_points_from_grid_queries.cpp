#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int m = grid.size(), n = grid[0].size();
    int k = queries.size();
    vector<int> answer(k, 0);

    vector<pair<int, int>> sorted_queries;
    for (int i = 0; i < k; i++) {
        sorted_queries.emplace_back(queries[i], i);
    }
    sort(sorted_queries.begin(), sorted_queries.end());

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> directions = {-1, 0, 1, 0, -1};

    pq.emplace(grid[0][0], make_pair(0, 0));
    visited[0][0] = true;
    
    int points = 0; 

    for (auto [query, index] : sorted_queries) {
        while (!pq.empty() && pq.top().first < query) {
            auto [value, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            points++;

            for (int d = 0; d < 4; d++) {
                int nr = r + directions[d], nc = c + directions[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.emplace(grid[nr][nc], make_pair(nr, nc));
                    visited[nr][nc] = true;
                }
            }
        }
        answer[index] = points;
    }
    return answer;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 5, 7},
        {3, 5, 1}
    };
    vector<int> queries = {5, 6, 2};

    vector<int> result = maxPoints(grid, queries);

    cout << "Output: ";
    for (int points : result) {
        cout << points << " ";
    }
    cout << endl;
    
    return 0;
}
