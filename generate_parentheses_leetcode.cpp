#include <iostream>
#include <vector>

using namespace std;

void generateParenthesisHelper(int n, int openCount, int closeCount, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    if (openCount < n) {
        generateParenthesisHelper(n, openCount + 1, closeCount, current + "(", result);
    }
    
    if (closeCount < openCount) {
        generateParenthesisHelper(n, openCount, closeCount + 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n, 0, 0, "", result);
    return result;
}

int main() {
    int n;
    cin >> n;  // Take input from the user

    vector<string> result = generateParenthesis(n);

    for (const string& s : result) {
        cout << s << endl;
    }
    
    return 0;
}
