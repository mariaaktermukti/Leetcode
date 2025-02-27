#include <iostream>
#include <deque>

using namespace std;

int get_ticket_time(int N) {
    deque<int> queue;
    
    // Initialize the queue with positions starting from 1
    for (int i = 1; i <= 1000; i++) {  // Arbitrarily large number for the queue
        queue.push_back(i);
    }

    int seconds = 0;
    
    // Keep processing the queue until person at position N gets their ticket
    while (!queue.empty()) {
        seconds++;

        // The first and third persons in the current queue will get tickets
        int first = queue.front();
        queue.pop_front();
        
        int third = -1;
        if (!queue.empty()) {
            third = queue.front();
            queue.pop_front();
        }

        // If position N is at 1st or 3rd, return the current second
        if (first == N || third == N) {
            return seconds;
        }

        // Move the second person to the 1st position
        if (!queue.empty()) {
            int second = queue.front();
            queue.pop_front();
            queue.push_front(second);
        }
    }

    return -1;  // This should never happen for valid inputs
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N;
        cin >> N;  // Your initial position in the queue
        cout << get_ticket_time(N) << endl;
    }

    return 0;
}
