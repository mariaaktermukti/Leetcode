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
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true; 
    if (!left || !right) return false; 
    if (left->val != right->val) return false; 
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true; 
    return isMirror(root->left, root->right);
}

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

TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < nodes.size()) {
        TreeNode* parent = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            parent->left = new TreeNode(nodes[i]);
            q.push(parent->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            parent->right = new TreeNode(nodes[i]);
            q.push(parent->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    int n;
    cin >> n; 
    
    vector<int> treeNodes(n);
    for (int i = 0; i < n; i++) {
        cin >> treeNodes[i]; 
    }

    TreeNode* root = buildTree(treeNodes);
    
    cout << "Original Tree (Level Order): ";
    levelOrder(root);

    cout << "Is Symmetric? " << (isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}
