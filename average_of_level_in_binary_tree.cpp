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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> result;
        if (!root) return result; 
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            int levelSize = q.size();
            long long sum = 0; 

            for (int i = 0; i < levelSize; i++) 
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(static_cast<double>(sum) / levelSize);
        }

        return result;
    }
};

TreeNode* insertLevelOrder(vector<int> &arr, int i) 
{
    if (i >= arr.size() || arr[i] == -1) return nullptr; 
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    return root;
}

int main() 
{
    Solution solution;

    vector<int> arr = {3, 9, 20, -1, -1, 15, 7}; 
    TreeNode* root = insertLevelOrder(arr, 0);

    vector<double> averages = solution.averageOfLevels(root);

    cout << "[";
    for (size_t i = 0; i < averages.size(); i++) 
    {
        cout << averages[i];
        if (i != averages.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
