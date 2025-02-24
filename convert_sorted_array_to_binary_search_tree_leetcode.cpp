#include <iostream>
#include <vector>
#include <queue>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if (nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) 
    {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        
        return root;
    }
};

void printTree(TreeNode* root) 
{
    if (!root) 
    {
        cout << "[]" << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    
    while (!q.empty()) 
    {
        TreeNode* current = q.front();
        q.pop();
        
        if (current) 
        {
            cout << current->val << ",";
            q.push(current->left);
            q.push(current->right);
        } 
        else 
        {
            cout << "null,";
        }
    }
    
    cout << "\b]" << endl;
}

int main() 
{
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "Level-order representation of the BST:" << endl;
    printTree(root);

    return 0;
}
