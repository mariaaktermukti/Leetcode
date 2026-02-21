#include <bits/stdc++.h>
using namespace std;

int countPrimeSetBits(int left, int right) {
    int count = 0;
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

    for (int i = left; i <= right; i++) {
        int num = i;
        int bits = 0;

        while (num) {
            bits += (num & 1);
            num >>= 1;
        }

        if (primes.count(bits)) {
            count++;
        }
    }

    return count;
}

int main() {
    int left, right;
    cin >> left >> right;

    cout << countPrimeSetBits(left, right) << endl;

    return 0;
}