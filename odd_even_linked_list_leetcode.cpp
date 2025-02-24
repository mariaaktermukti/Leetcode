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

class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next) 
        {
            return head; 
        }

        ListNode* odd = head;           
        ListNode* even = head->next;     
        ListNode* even_head = even;      

        while (even && even->next) 
        {
            odd->next = even->next;     
            odd = odd->next;             
            even->next = odd->next;      
            even = even->next;          
        }

        odd->next = even_head;           
        return head;
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
    vector<int> values = {2, 1, 3, 5, 6, 4, 7};

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.oddEvenList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
