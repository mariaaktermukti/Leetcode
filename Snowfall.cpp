#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A, B, C, D;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % 6 == 0) A.push_back(x);
            else if (x % 2 == 0) B.push_back(x);
            else if (x % 3 == 0) C.push_back(x);
            else D.push_back(x);
        }
        for (int x : A) cout << x << ' ';
        for (int x : B) cout << x << ' ';
        for (int x : D) cout << x << ' ';
        for (int x : C) cout << x << ' ';
        cout << endl;
    }
    return 0;
}