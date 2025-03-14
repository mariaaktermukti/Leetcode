#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; 
        
        unordered_map<Node*, Node*> nodeMap;
        
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];  
            nodeMap[curr]->random = nodeMap[curr->random]; 
            curr = curr->next;
        }

        return nodeMap[head];
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "[" << temp->val << ", ";
        if (temp->random) cout << temp->random->val;
        else cout << "null";
        cout << "] ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;                    
    head->next->next->random = head->next->next->next->next; 
    head->next->next->next->random = head->next->next; 
    head->next->next->next->next->random = head;  

    cout << "Original list:\n";
    printList(head);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(head);

    cout << "\nCopied list:\n";
    printList(copiedHead);

    return 0;
}
