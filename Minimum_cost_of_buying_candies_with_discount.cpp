#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int minimumCost(vector<int> &cost)
{
    sort(cost.begin(), cost.end(), comp);

    int sum = 0;

    for (int i = 0; i < cost.size(); i += 3)
    {
        sum += cost[i];

        if (i + 1 < cost.size())
        {
            sum += cost[i + 1];
        }
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cout << minimumCost(cost) << endl;

    return 0;
}