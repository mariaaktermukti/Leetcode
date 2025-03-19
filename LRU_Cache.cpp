#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity; 
    list<pair<int, int>> cache; 
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; 

public:
    LRUCache(int cap) {
        this->capacity = cap; 
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        auto it = cacheMap[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cache.erase(it);
        }
        else if (cache.size() >= capacity) {
            auto last = cache.back();
            cacheMap.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        cacheMap[key] = cache.begin();
    }
};

int main() {
    LRUCache lRUCache(2); 
    
    lRUCache.put(1, 1); 
    lRUCache.put(2, 2); 
    cout << lRUCache.get(1) << endl; 
    
    lRUCache.put(3, 3); 
    cout << lRUCache.get(2) << endl; 
    
    lRUCache.put(4, 4); 
    cout << lRUCache.get(1) << endl; 
    cout << lRUCache.get(3) << endl; 
    cout << lRUCache.get(4) << endl; 

    return 0;
}
