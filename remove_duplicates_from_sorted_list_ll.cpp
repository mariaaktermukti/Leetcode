#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);  // Dummy node before the head
        ListNode* prev = dummy;                   // Pointer to track unique nodes
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // Skip duplicates
            } else {
                prev = prev->next; // Move prev only when no duplicate
            }
            head = head->next; // Move forward
        }

        return dummy->next; // Return updated list
    }
};

// Function to insert a new node at the end of the linked list
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;
    cout << "Enter the sorted linked list values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(head, val);
    }

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "Updated List after removing duplicates: ";
    printList(head);

    return 0;
}
