#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) return root; 

        if (key < root->val) 
        {
            root->left = deleteNode(root->left, key); 
        } 
        else if (key > root->val) 
        {
            root->right = deleteNode(root->right, key); 
        } 
        else 
        {
            if (!root->left) 
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (!root->right) 
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 
            else 
            {
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original BST (in-order): ";
    printTree(root);
    cout << endl;

    Solution solution;
    root = solution.deleteNode(root, 3);

    cout << "BST after deleting 3 (in-order): ";
    printTree(root);
    cout << endl;

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    cout << "Original BST (in-order): ";
    printTree(root2);
    cout << endl;

    root2 = solution.deleteNode(root2, 0);

    cout << "BST after deleting 0 (in-order): ";
    printTree(root2);
    cout << endl;

    TreeNode* root3 = nullptr;

    cout << "Original BST (in-order): ";
    printTree(root3);
    cout << endl;

    root3 = solution.deleteNode(root3, 0);

    cout << "BST after deleting 0 (in-order): ";
    printTree(root3);
    cout << endl;

    return 0;
}