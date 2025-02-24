#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> prefixProducts; 
    int lastZeroIndex;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1); 
        lastZeroIndex = -1; 
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);
            lastZeroIndex = prefixProducts.size() - 1;
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size() - 1;
        if (n - k < lastZeroIndex) return 0; 
        return prefixProducts[n] / prefixProducts[n - k];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;

    productOfNumbers.add(3);  
    productOfNumbers.add(0);  
    productOfNumbers.add(2);  
    productOfNumbers.add(5);  
    productOfNumbers.add(4);  
    
    cout << productOfNumbers.getProduct(2) << endl;
    cout << productOfNumbers.getProduct(3) << endl; 
    cout << productOfNumbers.getProduct(4) << endl;
    
    productOfNumbers.add(8);
    
    cout << productOfNumbers.getProduct(2) << endl;
    
    return 0;
}
