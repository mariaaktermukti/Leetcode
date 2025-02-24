#include <iostream>
#include <queue>
#include <climits>
#include <vector>

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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; 

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN; 
        int maxLevel = 0; 
        int level = 0; 

        while (!q.empty()) {
            level++;
            int levelSize = q.size(); 
            int currentSum = 0; 

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                currentSum += currentNode->val;

                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};

TreeNode* createTree(const vector<int>& nodes, int index = 0) {
    if (index >= nodes.size() || nodes[index] == INT_MIN) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[index]);
    root->left = createTree(nodes, 2 * index + 1);
    root->right = createTree(nodes, 2 * index + 2);
    return root;
}

int main() {
    Solution solution;

    vector<int> nodes1 = {1, 7, 0, 7, -8, INT_MIN, INT_MIN}; 
    TreeNode* root1 = createTree(nodes1);
    int result1 = solution.maxLevelSum(root1);
    cout << "Example 1 Output: " << result1 << endl;

    vector<int> nodes2 = {989, INT_MIN, 10250, 98693, -89388, INT_MIN, INT_MIN, INT_MIN, -32127};
    TreeNode* root2 = createTree(nodes2);
    int result2 = solution.maxLevelSum(root2);
    cout << "Example 2 Output: " << result2 << endl; 

    vector<int> nodes3 = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root3 = createTree(nodes3);
    int result3 = solution.maxLevelSum(root3);
    cout << "Example 3 Output: " << result3 << endl; 

    vector<int> nodes4 = {10};
    TreeNode* root4 = createTree(nodes4);
    int result4 = solution.maxLevelSum(root4);
    cout << "Example 4 Output: " << result4 << endl; 

    return 0;
}