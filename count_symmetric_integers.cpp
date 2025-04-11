#include <iostream>
#include <string>
using namespace std;

bool isSymmetric(int num) {
    string s = to_string(num);
    int n = s.size();
    if (n % 2 != 0) return false;

    int half = n / 2;
    int sumFirstHalf = 0, sumSecondHalf = 0;

    for (int i = 0; i < half; ++i) {
        sumFirstHalf += s[i] - '0';
        sumSecondHalf += s[half + i] - '0';
    }

    return sumFirstHalf == sumSecondHalf;
}

int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int num = low; num <= high; ++num) {
        if (isSymmetric(num))
            count++;
    }
    return count;
}

int main() {
    int low, high;
    cout << "Enter low: ";
    cin >> low;
    cout << "Enter high: ";
    cin >> high;

    int result = countSymmetricIntegers(low, high);
    cout << "Number of symmetric integers: " << result << endl;

    return 0;
}
