#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> height(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        stack<int> st;
        for (int j = 0; j <= cols; j++)
        {
            int currHeight = (j == cols) ? 0 : height[j];

            while (!st.empty() && currHeight < height[st.top()])
            {
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? j : j - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(j);
        }
    }

    return maxArea;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix) << "\n";
    return 0;
}
