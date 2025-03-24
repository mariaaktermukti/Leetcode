#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) 
    {
        std::sort(meetings.begin(), meetings.end());

        int totalMeetingDays = 0;
        int prevStart = -1, prevEnd = -1;

        for (const auto& meeting : meetings) 
        {
            int start = meeting[0];
            int end = meeting[1];

            if (start > prevEnd) 
            {
                totalMeetingDays += (prevEnd - prevStart + 1);
                prevStart = start;
                prevEnd = end;
            } 
            else 
            {
                prevEnd = std::max(prevEnd, end);
            }
        }
        totalMeetingDays += (prevEnd - prevStart + 1);

        return days - totalMeetingDays;
    }
};

int main() 
{
    Solution solution;
    int days = 10;
    std::vector<std::vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
    
    std::cout << "Free days: " << solution.countDays(days, meetings) << std::endl;
    
    return 0;
}
