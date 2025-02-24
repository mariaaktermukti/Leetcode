#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if (!root) return 0; 

        int sum = 0;

        if (root->val >= low && root->val <= high) 
        {
            sum += root->val;
        }

        if (root->val > low) 
        {
            sum += rangeSumBST(root->left, low, high);
        }

        if (root->val < high) 
        {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
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
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) 
        {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) 
        {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() 
{
    vector<int> nodes = {10, 5, 15, 3, 7, -1, 18};
    int low = 7, high = 15;

    TreeNode* root = buildTree(nodes);
    Solution solution;
    int result = solution.rangeSumBST(root, low, high);
    cout << "Example 1 Output: " << result << endl;

    nodes = {10, 5, 15, 3, 7, 13, 18, 1, -1, 6};
    low = 6, high = 10;

    root = buildTree(nodes);
    result = solution.rangeSumBST(root, low, high);
    cout << "Example 2 Output: " << result << endl;

    return 0;
}
