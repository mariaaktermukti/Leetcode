#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long quotient = 0;
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            absDividend -= tempDivisor;
            quotient += multiple;
        }
        quotient = isNegative ? -quotient : quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};

int main() {
    Solution solution;

    int dividend1 = 10, divisor1 = 3;
    cout << "10 / 3 = " << solution.divide(dividend1, divisor1) << endl;

    int dividend2 = 7, divisor2 = -3;
    cout << "7 / -3 = " << solution.divide(dividend2, divisor2) << endl;

    int dividend3 = INT_MIN, divisor3 = -1;
    cout << "INT_MIN / -1 = " << solution.divide(dividend3, divisor3) << endl;

    int dividend4 = INT_MIN, divisor4 = 2;
    cout << "INT_MIN / 2 = " << solution.divide(dividend4, divisor4) << endl;

    return 0;
}
