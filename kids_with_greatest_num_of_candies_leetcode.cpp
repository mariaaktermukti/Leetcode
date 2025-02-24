#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
     {
        int maxCandies = candies[0];
        for (int candy : candies) 
        {
            if (candy > maxCandies) 
            {
                maxCandies = candy;
            }
        }
        vector<bool> result;
        for (int candy : candies) 
        {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        
        return result;
    }
};

int main() 
{
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;

    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;

    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;

    Solution solution;

    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    cout << "Result 1: ";
    for (bool res : result1) 
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);
    cout << "Result 2: ";
    for (bool res : result2) 
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    vector<bool> result3 = solution.kidsWithCandies(candies3, extraCandies3);
    cout << "Result 3: ";
    for (bool res : result3) 
    {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
