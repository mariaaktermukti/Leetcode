#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1); 
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = hammingWeight(n);
    cout << "Number of set bits (Hamming weight): " << result << endl;

    return 0;
}
