#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1); 
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t n;
    cout << "Enter a 32-bit unsigned integer: ";
    cin >> n;

    uint32_t reversed = reverseBits(n);
    cout << "Reversed bits: " << reversed << endl;

    return 0;
}
