#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the points (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int maxPoints = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<string, int> slopeCount;
        int duplicates = 1;

        for (int j = i + 1; j < n; ++j) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicates++; 
            } else {
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy); 
                }

                string slopeKey = to_string(dy) + "/" + to_string(dx);
                slopeCount[slopeKey]++;
            }
        }

        int currentMax = 0;
        for (auto& entry : slopeCount) {
            currentMax = max(currentMax, entry.second);
        }

        maxPoints = max(maxPoints, currentMax + duplicates);
    }

    cout << "Maximum points on a straight line: " << maxPoints << endl;

    return 0;
}
