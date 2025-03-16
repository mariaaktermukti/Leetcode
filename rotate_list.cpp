#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head; 

        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;  
        return newHead;
    }
};

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the number of nodes: ";
    cin >> n;

    ListNode* head = nullptr;
    cout << "Enter the linked list values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(head, val);
    }

    cout << "Enter k (number of rotations): ";
    cin >> k;

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
