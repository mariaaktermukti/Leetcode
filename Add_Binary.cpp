#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    
    return result;
}

int main() {
    string a, b;
    cout << "Enter first binary string: ";
    cin >> a;
    cout << "Enter second binary string: ";
    cin >> b;

    string result = addBinary(a, b);
    cout << "Sum: " << result << endl;

    return 0;
}
