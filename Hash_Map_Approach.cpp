#include <iostream>
#include <unordered_map>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> freq;
    int majority = -1;

    for(int i = 0; i < n; i++) 
    {
        freq[arr[i]]++;
        if(freq[arr[i]] > n / 2) 
        {
            majority = arr[i];
            break;
        }
    }

    if(majority != -1)
        cout << "Majority element: " << majority << endl;
    else
        cout << "No majority element found." << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)