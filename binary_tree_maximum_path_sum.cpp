#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int maxSum;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;  
        dfs(root);
        return maxSum;
    }
};

int main() {
    int n;
    cin >> n; 
    vector<string> nodes(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nodes[i]; 
    }

    TreeNode* root = buildTree(nodes);
    Solution sol;
    cout << sol.maxPathSum(root) << endl; 

    return 0;
}
