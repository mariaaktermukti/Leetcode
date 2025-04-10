#include <iostream>
#include <string>

using namespace std;

int main() {
    long long start, finish;
    int limit;
    string s;

    cin >> start >> finish >> limit >> s;

    long long count = 0;
    int slen = s.length();

    long long base = 1;
    for (int i = 0; i < slen; i++) base *= 10;
    long long suffix = stoll(s);

    for (long long prefix = 0; ; ++prefix) {
        long long num = prefix * base + suffix;

        if (num > finish) break;
        if (num < start) continue;

        string num_str = to_string(num);
        bool valid = true;

        for (char ch : num_str) {
            if (ch - '0' > limit) {
                valid = false;
                break;
            }
        }

        if (valid) count++;
    }

    cout << count << endl;

    return 0;
}
