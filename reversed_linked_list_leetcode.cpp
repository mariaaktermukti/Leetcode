#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* current = head; 

        while (current != nullptr) 
        {
            ListNode* nextTemp = current->next; 
            current->next = prev;             
            prev = current;                     
            current = nextTemp;               
        }

        return prev; 
    }
};

ListNode* createList(const vector<int>& values) 
{
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) 
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) 
{
    while (head) 
    {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
