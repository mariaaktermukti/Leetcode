#include <iostream>
#include <vector>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isAlternating = true;

        for (int j = 0; j < k - 1; j++) {
            if (colors[(i + j) % n] == colors[(i + j + 1) % n]) {
                isAlternating = false;
                break;
            }
        }

        if (isAlternating) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter number of tiles: ";
    cin >> n;

    vector<int> colors(n);
    cout << "Enter tile colors (0 for red, 1 for blue): ";
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    cout << "Enter group size (k): ";
    cin >> k;

    int result = numberOfAlternatingGroups(colors, k);
    cout << "Number of alternating groups: " << result << endl;

    return 0;
}
