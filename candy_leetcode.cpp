#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }
        return totalCandies;
    }
};

void printResult(vector<int>& ratings) {
    Solution sol;
    cout << "Ratings: ";
    for (int r : ratings) cout << r << " ";
    cout << "\nMinimum candies needed: " << sol.candy(ratings) << "\n\n";
}

int main() {
    vector<int> ratings1 = {1, 0, 2};
    printResult(ratings1); 

    vector<int> ratings2 = {1, 2, 2};
    printResult(ratings2); 
    
    return 0;
}
