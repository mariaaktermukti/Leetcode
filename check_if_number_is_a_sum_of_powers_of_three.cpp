#include <iostream>
using namespace std;

bool checkPowersOfThree(int n) {
    while (n > 0) {
        if (n % 3 == 2) return false;
        n /= 3; 
    }
    return true; 
}

int main() {
    int n;
    cin >> n; 
    if (checkPowersOfThree(n)) 
        cout << "true" << endl;
    else 
        cout << "false" << endl;
    
    return 0;
}
