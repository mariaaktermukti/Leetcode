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

class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (!root) return nullptr; 
        if (root->val == val) return root; 
        if (val < root->val) return searchBST(root->left, val); 
        return searchBST(root->right, val); 
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

void printTree(TreeNode* root) 
{
    if (!root) 
    {
        cout << "[]";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    cout << "[";

    while (!q.empty()) 
    {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) 
        {
            cout << curr->val << ",";
            q.push(curr->left);
            q.push(curr->right);
        } 
        else 
        {
            cout << "null,";
        }
    }
    cout << "]";
}

int main() 
{
    vector<int> nodes = {4, 2, 7, 1, 3};
    int val = 2;

    TreeNode* root = buildTree(nodes);
    Solution solution;
    TreeNode* result = solution.searchBST(root, val);

    cout << "Example 1 Output: ";
    printTree(result);
    cout << endl;

    nodes = {4, 2, 7, 1, 3};
    val = 5;

    root = buildTree(nodes);
    result = solution.searchBST(root, val);

    cout << "Example 2 Output: ";
    printTree(result);
    cout << endl;

    return 0;
}

