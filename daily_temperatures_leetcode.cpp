#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; 

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx;
            }
            st.push(i); 
        }

        return answer;
    }
};

int main() {
    Solution solution;
    
    vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = solution.dailyTemperatures(temperatures1);
    cout << "Example 1 Output: ";
    for (int days : result1) {
        cout << days << " ";
    }
    cout << endl;

    vector<int> temperatures2 = {30, 40, 50, 60};
    vector<int> result2 = solution.dailyTemperatures(temperatures2);
    cout << "Example 2 Output: ";
    for (int days : result2) {
        cout << days << " ";
    }
    cout << endl;

    vector<int> temperatures3 = {30, 60, 90};
    vector<int> result3 = solution.dailyTemperatures(temperatures3);
    cout << "Example 3 Output: ";
    for (int days : result3) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
