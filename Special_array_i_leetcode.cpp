#include <iostream>
#include <vector>
using namespace std;

bool isArraySpecial(vector<int>& nums) 
{
    if (nums.size() <= 1) 
    {
        return true;
    }

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) ||  
            (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0))
            { 
            return false;
        }
    }

    return true;
};

int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (isArraySpecial(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
