#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        if (len == 1) {
            return to_string(num - 1);
        }

        vector<long long> candidates;

        candidates.push_back(pow(10, len - 1) - 1);

        candidates.push_back(pow(10, len) + 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (long long i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string palindrome = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(palindrome));
        }

        if (n == string(len, '1') + "0") {
            candidates.push_back(stoll(string(len - 1, '9')));
        }
        candidates.erase(remove(candidates.begin(), candidates.end(), num), candidates.end());

        long long closest = -1;
        for (long long candidate : candidates) {
            if (closest == -1 ||
                abs(candidate - num) < abs(closest - num) ||
                (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};

int main() {
    Solution solution;
    vector<string> testCases = {"123", "1", "9", "11", "100", "999", "1000", "12321", "10000000000000000", "99999999999999999"};
    for (const string& testCase : testCases) {
        cout << "Input: " << testCase << "\n";
        string result = solution.nearestPalindromic(testCase);
        cout << "Closest palindrome: " << result << "\n\n";
    }

    return 0;
}