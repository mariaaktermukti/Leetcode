#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans;

    for (int b = 0; b < 8; b++) 
    {
        vector<int> x, y;
        for (int i = 1; i <= n; i++) 
        {
            if (i & (1 << b)) 
            {
                x.push_back(i);
            } 
            else 
            {
                y.push_back(i);
            }
        }

        vector<int> xy(x.begin(), x.end());
        xy.insert(xy.end(), y.begin(), y.end());
        ans.push_back(xy);

        vector<int> yx(y.begin(), y.end());
        yx.insert(yx.end(), x.begin(), x.end());
        ans.push_back(yx);

        vector<int> x_rev(x.rbegin(), x.rend());
        vector<int> y_rev(y.rbegin(), y.rend());
        x_rev.insert(x_rev.end(), y_rev.begin(), y_rev.end());
        ans.push_back(x_rev);

        vector<int> y_rev_x_rev(y.rbegin(), y.rend());
        y_rev_x_rev.insert(y_rev_x_rev.end(), x.rbegin(), x.rend());
        ans.push_back(y_rev_x_rev);
    }

    cout << 32 << endl;
    for (const auto& p : ans) 
    {
        for (int num : p) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}