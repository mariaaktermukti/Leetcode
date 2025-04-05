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
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0}; 
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int leftDepth = left.second, rightDepth = right.second;

        if (leftDepth == rightDepth) {
            return {node, leftDepth + 1};
        } 
        return (leftDepth > rightDepth) ? make_pair(left.first, leftDepth + 1) 
                                        : make_pair(right.first, rightDepth + 1);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
void printTree(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution solution;
    TreeNode* result = solution.lcaDeepestLeaves(root);

    cout << "LCA of Deepest Leaves: ";
    printTree(result);
    cout << endl;

    return 0;
}
