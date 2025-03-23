#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (topNode->right) {
            pushLeft(topNode->right);
        }
        return topNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

TreeNode* createBST() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    return root;
}

int main() {
    TreeNode* root = createBST();
    BSTIterator bstIterator(root);

    while (bstIterator.hasNext()) {
        cout << bstIterator.next() << " ";
    }
    
    return 0;
}
