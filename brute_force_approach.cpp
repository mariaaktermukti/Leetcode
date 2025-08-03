#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int majorityElement = -1;

    // Brute Force Logic
    for(int i = 0; i < n; i++) 
    {
        int count = 0;

        for(int j = 0; j < n; j++) 
        {
            if(arr[i] == arr[j]) 
            {
                count++;
            }
        }

        if(count > n / 2) 
        {
            majorityElement = arr[i];
            break;
        }
    }

    if(majorityElement != -1) 
    {
        cout << "Majority element is: " << majorityElement << endl;
    } 
    else 
    {
        cout << "No majority element found." << endl;
    }

    return 0;
}


//  Time Complexity: O(n²)
// Space Complexity: O(1)
