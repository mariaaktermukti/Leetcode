#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inorder(root, k, count, result);
        return result;
    }

private:
    void inorder(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;

        inorder(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right, k, count, result);
    }
};
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);

    Solution sol;
    int k = 3;
    cout << "The " << k << "rd smallest element is: " << sol.kthSmallest(root, k) << endl;

    return 0;
}
