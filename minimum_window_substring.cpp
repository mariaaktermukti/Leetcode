#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> t_freq, window;
    for (char c : t) t_freq[c]++;

    int left = 0, right = 0, required = t_freq.size();
    int formed = 0, minLen = INT_MAX, startIdx = 0;

    while (right < s.length()) {
        char c = s[right];
        window[c]++;

        if (t_freq.count(c) && window[c] == t_freq[c])
            formed++;

        while (formed == required) { 
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }
            char leftChar = s[left];
            window[leftChar]--;
            if (t_freq.count(leftChar) && window[leftChar] < t_freq[leftChar])
                formed--;
            left++;
        }
        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}
