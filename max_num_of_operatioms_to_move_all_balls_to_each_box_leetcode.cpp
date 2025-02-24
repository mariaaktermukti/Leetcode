#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        int operations = 0, balls = 0;
        for (int i = 0; i < n; ++i) 
        {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }

        operations = 0;
        balls = 0;
        for (int i = n - 1; i >= 0; --i) 
        {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }

        return answer;
    }
};

int main() 
{
    Solution solution;
    string boxes1 = "110";
    string boxes2 = "001011";

    vector<int> result1 = solution.minOperations(boxes1);
    vector<int> result2 = solution.minOperations(boxes2);

    for (int val : result1) 
    {
        printf("%d ", val);
    }
    printf("\n");

    for (int val : result2) 
    {
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}