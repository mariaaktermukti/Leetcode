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
    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};

void levelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    
    vector<int> result;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1);
        }
    }

    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }
    
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = solution.buildTree(preorder, inorder);
    
    cout << "Level Order Output: ";
    levelOrder(root); 

    return 0;
}
