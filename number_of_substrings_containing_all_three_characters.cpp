#include <iostream>
#include <string>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.length();
    int count[3] = {0}; 
    int i = 0; 
    int result = 0;
    
    for (int j = 0; j < n; ++j) {
        ++count[s[j] - 'a']; 
        
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            result += n - j;
            --count[s[i] - 'a']; 
            ++i;
        }
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = numberOfSubstrings(s);
    cout << "Number of substrings containing at least one 'a', 'b', and 'c': " << result << endl;

    return 0;
}
