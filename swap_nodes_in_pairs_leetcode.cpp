#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},  
        {},           
        {1},          
        {1, 2, 3}      
    };
    
    Solution sol;
    
    for (const auto& testCase : testCases) {
        ListNode* head = createList(testCase);
        cout << "Original list: ";
        printList(head);
        
        ListNode* swapped = sol.swapPairs(head);
        cout << "Swapped list:  ";
        printList(swapped);
        cout << endl;
        
        freeList(swapped);
    }
    
    return 0;
}
