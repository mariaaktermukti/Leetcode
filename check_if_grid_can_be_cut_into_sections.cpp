#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        set<int> x_cuts, y_cuts;
        for (auto& rect : rectangles) {
            x_cuts.insert(rect[0]);
            x_cuts.insert(rect[2]);
            y_cuts.insert(rect[1]);
            y_cuts.insert(rect[3]);
        }

        vector<int> x_sorted(x_cuts.begin(), x_cuts.end());
        vector<int> y_sorted(y_cuts.begin(), y_cuts.end());

        if (checkCuts(x_sorted, rectangles, true)) return true;

        if (checkCuts(y_sorted, rectangles, false)) return true;

        return false;
    }

private:
    bool checkCuts(vector<int>& sortedCuts, vector<vector<int>>& rectangles, bool isVertical) {
        int m = sortedCuts.size();
        for (int i = 1; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int cut1 = sortedCuts[i];
                int cut2 = sortedCuts[j];

                vector<int> group(3, 0);
                for (auto& rect : rectangles) {
                    int val = isVertical ? rect[0] : rect[1]; 
                    int endVal = isVertical ? rect[2] : rect[3]; 

                    if (val < cut1) {
                        if (endVal > cut1) break; 
                        group[0]++;
                    } else if (val < cut2) {
                        if (endVal > cut2) break; 
                        group[1]++;
                    } else {
                        group[2]++;
                    }
                }

                if (group[0] > 0 && group[1] > 0 && group[2] > 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> rectangles(m, vector<int>(4));
    for (int i = 0; i < m; i++) {
        cin >> rectangles[i][0] >> rectangles[i][1] >> rectangles[i][2] >> rectangles[i][3];
    }

    Solution sol;
    if (sol.checkValidCuts(n, rectangles)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
