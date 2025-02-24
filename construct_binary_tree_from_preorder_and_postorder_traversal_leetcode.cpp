#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
                    vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        if (preStart == preEnd)
            return root;
        
        int leftRootValue = preorder[preStart + 1];
        int postLeftRootIndex = find(postorder.begin() + postStart, postorder.begin() + postEnd, leftRootValue) - postorder.begin();
        
        int leftSubtreeSize = postLeftRootIndex - postStart + 1;
        
        root->left = build(preorder, preStart + 1, preStart + leftSubtreeSize, 
                           postorder, postStart, postLeftRootIndex);
        root->right = build(preorder, preStart + leftSubtreeSize + 1, preEnd, 
                            postorder, postLeftRootIndex + 1, postEnd - 1);
        
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    Solution solution;
    TreeNode* root = solution.constructFromPrePost(preorder, postorder);
    
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}
