#include <bits/stdc++.h>
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
    unordered_map<int, int> inorderMap;
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        root->right = buildTreeHelper(inorder, postorder, inorderIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1; 
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Solution sol;
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode* root1 = sol.buildTree(inorder1, postorder1);

    cout << "Preorder of the constructed tree (Example 1): ";
    preorderTraversal(root1); 
    cout << endl;

    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode* root2 = sol.buildTree(inorder2, postorder2);

    cout << "Preorder of the constructed tree (Example 2): ";
    preorderTraversal(root2);
    cout << endl;

    return 0;
}
