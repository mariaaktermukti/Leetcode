#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) 
    {
        return dfs(root, INT_MIN); 
    }

private:
    int dfs(TreeNode* node, int maxSoFar) 
    {
        if (!node) return 0; 

        int count = 0;
        if (node->val >= maxSoFar) 
        {
            count = 1; 
            maxSoFar = node->val; 
        }

        count += dfs(node->left, maxSoFar);
        count += dfs(node->right, maxSoFar);

        return count; 
    }
};

void test() 
{
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    Solution sol;
    cout << "Test Case 1: " << sol.goodNodes(root1) << " (Expected: 4)" << endl;

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(2);

    cout << "Test Case 2: " << sol.goodNodes(root2) << " (Expected: 3)" << endl;

    TreeNode* root3 = new TreeNode(1);

    cout << "Test Case 3: " << sol.goodNodes(root3) << " (Expected: 1)" << endl;
}

int main() {
    test();
    return 0;
}
