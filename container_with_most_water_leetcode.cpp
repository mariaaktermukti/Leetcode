#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;               
    int right = height.size() - 1; 
    int max_area = 0;           

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        int current_area = width * current_height;

        max_area = max(max_area, current_area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum Area: " << maxArea(height1) << endl; 

    vector<int> height2 = {1, 1};
    cout << "Maximum Area: " << maxArea(height2) << endl; 

    return 0;
}
