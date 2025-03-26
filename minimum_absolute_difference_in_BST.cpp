#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void inOrder(TreeNode* node, int &prev, int &minDiff) {
    if (!node) return;

    inOrder(node->left, prev, minDiff);

    if (prev != -1) {
        minDiff = min(minDiff, node->val - prev);
    }
    prev = node->val;

    inOrder(node->right, prev, minDiff);
}
int getMinimumDifference(TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1;
    inOrder(root, prev, minDiff);
    return minDiff;
}

int main() {
    int n;
    cout << "Enter number of nodes in BST: ";
    cin >> n;

    if (n < 2) {
        cout << "BST must have at least 2 nodes." << endl;
        return 0;
    }

    TreeNode* root = nullptr;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val); 
    }

    int result = getMinimumDifference(root);
    cout << "Minimum absolute difference: " << result << endl;

    return 0;
}
