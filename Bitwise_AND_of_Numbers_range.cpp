#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
}

int main() {
    int left, right;
    
    cout << "Enter left: ";
    cin >> left;
    
    cout << "Enter right: ";
    cin >> right;

    int result = rangeBitwiseAnd(left, right);

    cout << "Bitwise AND of range [" << left << ", " << right << "] is: " << result << endl;

    return 0;
}
