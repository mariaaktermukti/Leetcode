#include <iostream>
#include <cmath>
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
    int computeHeight(TreeNode* root) 
    {
        int height = 0;
        while (root) 
        {
            height++;
            root = root->left; 
        }
        return height;
    }

    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;
        
        int leftHeight = computeHeight(root->left);
        int rightHeight = computeHeight(root->right);

        if (leftHeight == rightHeight) 
        {
            return (1 << leftHeight) + countNodes(root->right);
        } 
        else 
        {
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};

TreeNode* insertLevelOrder(int arr[], int i, int n) 
{
    if (i >= n) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

int main() 
{
    Solution solution;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    TreeNode* root = insertLevelOrder(arr, 0, n);

    cout << "Number of nodes: " << solution.countNodes(root) << endl; 

    return 0;
}
