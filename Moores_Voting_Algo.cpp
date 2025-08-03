#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int candidate = -1, count = 0;

    // Phase 1: Find potential candidate
    for(int i = 0; i < n; i++) 
    {
        if(count == 0) 
        {
            candidate = arr[i];
            count = 1;
        } 
        else if(arr[i] == candidate) 
        {
            count++;
        } 
        else 
        {
            count--;
        }
    }

    // Phase 2: Verify candidate
    count = 0;
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] == candidate) count++;
    }

    if(count > n / 2)
        cout << "Majority element: " << candidate << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
