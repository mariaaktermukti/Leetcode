#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return 0;

        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;

        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, int currentSum, int targetSum, unordered_map<int, int>& prefixSumCount) 
    {
        if (!node) return 0;

        currentSum += node->val;

        int pathsToCurrentNode = prefixSumCount[currentSum - targetSum];

        prefixSumCount[currentSum]++;

        int totalPaths = pathsToCurrentNode + dfs(node->left, currentSum, targetSum, prefixSumCount)
                                         + dfs(node->right, currentSum, targetSum, prefixSumCount);

        prefixSumCount[currentSum]--;

        return totalPaths;
    }
};

TreeNode* buildTree(const vector<int>& nodes) 
{
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) 
    {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) 
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) 
        {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> treeNodes = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1}; 
    int targetSum = 8;

    TreeNode* root = buildTree(treeNodes);

    Solution solution;
    int result = solution.pathSum(root, targetSum);

    cout << "Number of paths that sum to " << targetSum << ": " << result << endl;

    return 0;
}
