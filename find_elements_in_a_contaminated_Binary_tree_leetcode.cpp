#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
private:
    TreeNode* root;
    unordered_set<int> recoveredValues;

    void recover(TreeNode* node, int val) {
        if (!node) return;
        
        node->val = val;
        recoveredValues.insert(val);
        
        if (node->left) recover(node->left, 2 * val + 1);
        if (node->right) recover(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        recover(root, 0);
    }
    
    bool find(int target) {
        return recoveredValues.count(target) > 0;
    }
};

int main() {
    TreeNode* root = new TreeNode(-1);
    root->right = new TreeNode(-1);
    
    FindElements findElements(root);
    
    cout << "find(1): " << (findElements.find(1) ? "true" : "false") << endl; 
    cout << "find(2): " << (findElements.find(2) ? "true" : "false") << endl; 

    delete root->right;
    delete root;
    
    return 0;
}
