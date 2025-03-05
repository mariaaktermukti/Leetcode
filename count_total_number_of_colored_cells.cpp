#include <iostream>

using namespace std;

long long coloredCells(int n) {
    return 1LL * (2 * n * (n - 1) + 1);
}

int main() {
    int n;
    cin >> n;  
    cout << coloredCells(n) << endl;
    return 0;
}
