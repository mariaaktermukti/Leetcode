#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLength = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;

        maxLength = max(maxLength, length);

        if (isLeft) {
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);         
        } else {
            dfs(node->right, true, length + 1);
            dfs(node->left, false, 1);   
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, false, 1);
        dfs(root->right, true, 1); 
        return maxLength;
    }
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution solution;

    vector<int> input1 = {1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1};
    TreeNode* root1 = buildTree(input1);
    cout << "Longest ZigZag Path (Test Case 1): " << solution.longestZigZag(root1) << endl;

    vector<int> input2 = {1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1};
    TreeNode* root2 = buildTree(input2);
    cout << "Longest ZigZag Path (Test Case 2): " << solution.longestZigZag(root2) << endl;

    vector<int> input3 = {1};
    TreeNode* root3 = buildTree(input3);
    cout << "Longest ZigZag Path (Test Case 3): " << solution.longestZigZag(root3) << endl;

    return 0;
}
