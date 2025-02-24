#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false; 
        }

        int index = valToIndex[val];
        int lastElement = nums.back();
        
        nums[index] = lastElement;
        valToIndex[lastElement] = index;
        
        nums.pop_back();
        
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << boolalpha;
    
    cout << "Insert 1: " << obj->insert(1) << "\n";  
    cout << "Remove 2: " << obj->remove(2) << "\n";   
    cout << "Insert 2: " << obj->insert(2) << "\n";  
    cout << "Random: " << obj->getRandom() << "\n";     
    cout << "Remove 1: " << obj->remove(1) << "\n";    
    cout << "Insert 2: " << obj->insert(2) << "\n"; 
    cout << "Random: " << obj->getRandom() << "\n";     
    
    delete obj;
    return 0;
}
