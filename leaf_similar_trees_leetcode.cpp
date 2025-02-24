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

class Solution 
{
public:
    void getLeafValues(TreeNode* root, vector<int>& leafValues) 
    {
        if (!root) return; 
        if (!root->left && !root->right) 
        {
            leafValues.push_back(root->val); 
            return;
        }
        getLeafValues(root->left, leafValues);  
        getLeafValues(root->right, leafValues); 
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leafValues1, leafValues2;
        getLeafValues(root1, leafValues1); 
        getLeafValues(root2, leafValues2); 
        return leafValues1 == leafValues2;
    }
};

TreeNode* buildTree(const vector<int>& values) 
{
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) 
    {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) 
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) 
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    cout << "Enter the values for the first tree in level-order (-1 for null nodes):" << endl;
    vector<int> tree1Values;
    int val;
    while (cin >> val && val != -2) 
    {   
        tree1Values.push_back(val);
    }
    TreeNode* root1 = buildTree(tree1Values);

    cout << "Enter the values for the second tree in level-order (-1 for null nodes):" << endl;
    vector<int> tree2Values;
    while (cin >> val && val != -2) 
    { 
        tree2Values.push_back(val);
    }
    TreeNode* root2 = buildTree(tree2Values);

    Solution solution;
    bool result = solution.leafSimilar(root1, root2);

    if (result) 
    {
        cout << "The two trees are leaf-similar." << endl;
    } 
    else 
    {
        cout << "The two trees are not leaf-similar." << endl;
    }

    return 0;
}
