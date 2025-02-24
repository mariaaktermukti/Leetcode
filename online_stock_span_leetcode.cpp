#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; 

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << endl;
    cout << stockSpanner.next(80) << endl;  
    cout << stockSpanner.next(60) << endl; 
    cout << stockSpanner.next(70) << endl;  
    cout << stockSpanner.next(60) << endl;  
    cout << stockSpanner.next(75) << endl;  
    cout << stockSpanner.next(85) << endl; 

    return 0;
}
