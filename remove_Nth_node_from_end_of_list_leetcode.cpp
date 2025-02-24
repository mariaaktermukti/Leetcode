#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}

void insertNode(ListNode*& head, int val) {
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
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;
    int n, val, size;

    cout << "Enter the number of nodes: ";
    cin >> size;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < size; i++) {
        cin >> val;
        insertNode(head, val);
    }

    cout << "Enter the position from end to remove: ";
    cin >> n;

    head = removeNthFromEnd(head, n);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
