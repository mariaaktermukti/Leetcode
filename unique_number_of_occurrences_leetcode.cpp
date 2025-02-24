#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    auto uniqueOccurrences = [](const vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        unordered_set<int> frequencySet;

        for (int num : arr) {
            frequencyMap[num]++;
        }
        for (const auto& [key, frequency] : frequencyMap) {
            if (frequencySet.find(frequency) != frequencySet.end()) {
                return false; 
            }
            frequencySet.insert(frequency);
        }

        return true; 
    };

    cout << (uniqueOccurrences(arr1) ? "true" : "false") << endl; 
    cout << (uniqueOccurrences(arr2) ? "true" : "false") << endl; 
    cout << (uniqueOccurrences(arr3) ? "true" : "false") << endl; 

    return 0;
}
