#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;  

        Node* leftmost = root;  

        while (leftmost) {
            Node* current = leftmost;  
            Node* prev = nullptr;  
            Node* nextLevelLeftmost = nullptr;  

            while (current) {
                if (current->left) {
                    if (prev) {
                        prev->next = current->left;
                    } else {
                        nextLevelLeftmost = current->left;
                    }
                    prev = current->left;
                }

                if (current->right) {
                    if (prev) {
                        prev->next = current->right;
                    } else {
                        nextLevelLeftmost = current->right;
                    }
                    prev = current->right;
                }
                current = current->next;
            }
            leftmost = nextLevelLeftmost;
        }

        return root;  
    }
};
void printLevelOrder(Node* root) {
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << "# ";
        levelStart = levelStart->left;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    solution.connect(root);

    printLevelOrder(root);

    return 0;
}
