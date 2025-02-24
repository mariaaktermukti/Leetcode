#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.size();
        int max_score = 0;

        int total_ones = count(s.begin(), s.end(), '1');
        int left_zeros = 0, right_ones = total_ones;

        for (int i = 0; i < n - 1; ++i) 
        { 
            if (s[i] == '0') 
            {
                left_zeros++;
            } 
            else 
            {
                right_ones--;
            }
            max_score = max(max_score, left_zeros + right_ones);
        }

        return max_score;
    }
};

int main() 
{
    Solution solution;
    string s1 = "011101";
    string s2 = "00111";
    string s3 = "1111";

    printf("%d\n", solution.maxScore(s1)); 
    printf("%d\n", solution.maxScore(s2)); 
    printf("%d\n", solution.maxScore(s3)); 

    return 0;
}