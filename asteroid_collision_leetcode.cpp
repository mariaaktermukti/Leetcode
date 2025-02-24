#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> stack;

        for (int asteroid : asteroids) 
        {
            bool destroyed = false;

            while (!stack.empty() && asteroid < 0 && stack.back() > 0) 
            {
                if (stack.back() < -asteroid) 
                {
                    stack.pop_back(); 
                }
                else if (stack.back() == -asteroid) 
                {
                    stack.pop_back();
                    destroyed = true;
                    break;
                } 
                else 
                {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) 
            {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};

int main() 
{
    Solution solution;

    vector<vector<int>> testCases = 
    {
        {5, 10, -5},      
        {8, -8},           
        {10, 2, -5},      
        {10, -10},      
        {-2, -1, 1, 2},   
        {1, -2, -2, -2}    
    };

    for (size_t i = 0; i < testCases.size(); ++i) 
    {
        vector<int> result = solution.asteroidCollision(testCases[i]);
        cout << "Test Case " << i + 1 << ": Input = {";
        for (size_t j = 0; j < testCases[i].size(); ++j) 
        {
            cout << testCases[i][j] << (j < testCases[i].size() - 1 ? ", " : "");
        }
        cout << "} -> Output = {";
        for (size_t j = 0; j < result.size(); ++j) 
        {
            cout << result[j] << (j < result.size() - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }

    return 0;
}
