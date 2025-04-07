#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return nullptr;
}

int main() {
    int n, pos;
    cout << "Enter number of nodes in linked list: ";
    cin >> n;

    if (n == 0) {
        cout << "No nodes in list." << endl;
        return 0;
    }

    vector<ListNode*> nodes(n);
    cout << "Enter node values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nodes[i] = new ListNode(val);
        if (i > 0) {
            nodes[i - 1]->next = nodes[i];
        }
    }

    ListNode* head = nodes[0];

    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1 && pos >= 0 && pos < n) {
        nodes[n - 1]->next = nodes[pos]; 
    }

    ListNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected in the list." << endl;
    }
    return 0;
}
