#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    heights.push_back(0);

    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    cout << "Largest Rectangle Area: " << maxArea << endl;

    return 0;
}
