#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result; 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); 
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (i == levelSize - 1) {
                    result.push_back(currentNode->val);
                }

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }
        }

        return result;
    }
};

TreeNode* createTree(const vector<int>& nodes, int index = 0) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = createTree(nodes, 2 * index + 1);
    root->right = createTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    Solution solution;

    vector<int> nodes1 = {1, 2, 3, -1, 5, -1, 4}; 
    TreeNode* root1 = createTree(nodes1);
    vector<int> result1 = solution.rightSideView(root1);
    cout << "Example 1 Output: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl; 

    vector<int> nodes2 = {1, 2, 3, 4, -1, -1, -1, 5};
    TreeNode* root2 = createTree(nodes2);
    vector<int> result2 = solution.rightSideView(root2);
    cout << "Example 2 Output: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl; 

    vector<int> nodes3 = {1, -1, 3};
    TreeNode* root3 = createTree(nodes3);
    vector<int> result3 = solution.rightSideView(root3);
    cout << "Example 3 Output: ";
    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl; 

    vector<int> nodes4 = {};
    TreeNode* root4 = createTree(nodes4);
    vector<int> result4 = solution.rightSideView(root4);
    cout << "Example 4 Output: ";
    for (int val : result4) {
        cout << val << " ";
    }
    cout << endl; 

    return 0;
}