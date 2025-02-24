#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void backtrack(unordered_map<char, int>& freq, int& count) {
        for (auto& [ch, f] : freq) {
            if (f > 0) {  
                count++;   
                freq[ch]--;
                
                backtrack(freq, count);
                
                freq[ch]++; 
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char ch : tiles) freq[ch]++;  
        
        int count = 0;
        backtrack(freq, count);
        return count;
    }
};

int main() {
    string tiles;
    cout << "Enter tiles: ";
    cin >> tiles;
    
    Solution sol;
    int result = sol.numTilePossibilities(tiles);
    
    cout << "Number of possible sequences: " << result << endl;
    
    return 0;
}
