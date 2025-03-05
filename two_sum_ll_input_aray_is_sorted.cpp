#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            left++; 
        } else {
            right--; 
        }
    }
    return {};
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices (1-based): " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;  
    }

    return 0;
}
