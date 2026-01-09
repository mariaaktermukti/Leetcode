#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    pair<int, TreeNode *> dfs(TreeNode *root)
    {
        if (!root)
            return {0, nullptr};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if (l.first > r.first)
            return {l.first + 1, l.second};

        if (r.first > l.first)
            return {r.first + 1, r.second};

        return {l.first + 1, root};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return dfs(root).second;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode *ans = sol.subtreeWithAllDeepest(root);

    cout << "Root of smallest subtree containing all deepest nodes: "
         << ans->val << endl;

    return 0;
}
