#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& nums) 
{
    int count = 0;
    int n = nums.size();
    
    for (int i = 0; i <= n - 3; i++) 
    {
        int first = nums[i];
        int middle = nums[i + 1];
        int third = nums[i + 2];
        
        if (middle % 2 == 0 && first + third == middle / 2) 
        {
            count++;
        }
    }
    
    return count;
}

int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }
    
    int result = countSubarrays(nums);
    cout << "Number of valid subarrays: " << result << endl;
    
    return 0;
}
