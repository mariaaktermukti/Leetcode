#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void sieveOfEratosthenes(int n, vector<bool>& isPrime) {
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false; 
    
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

vector<int> closestPrimes(int left, int right) {
    vector<bool> isPrime;
    sieveOfEratosthenes(right, isPrime);

    vector<int> primes;
    for (int i = left; i <= right; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    if (primes.size() < 2) {
        return {-1, -1};
    }

    vector<int> result = {-1, -1};
    int minDiff = INT_MAX;

    for (int i = 1; i < primes.size(); ++i) {
        int diff = primes[i] - primes[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result = {primes[i - 1], primes[i]};
        }
    }

    return result;
}

int main() {
    int left, right;
    cin >> left >> right;

    vector<int> result = closestPrimes(left, right);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
