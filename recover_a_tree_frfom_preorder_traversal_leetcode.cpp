#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <cctype>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        if (n == 0) return nullptr;
        
        stack<pair<TreeNode*, int>> st;
        
        int i = 0;
        while (i < n) {
            int level = 0;
            while (i < n && traversal[i] == '-') {
                level++;
                i++;
            }
            
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(value);
            
            while (!st.empty() && st.top().second >= level) {
                st.pop();
            }
            
            if (!st.empty()) {
                if (!st.top().first->left) {
                    st.top().first->left = node;
                } else {
                    st.top().first->right = node;
                }
            }
            
            st.push({node, level});
        }
        
        while (st.size() > 1) {
            st.pop();
        }
        
        return st.top().first;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution sol;
    
    string traversal1 = "1-2--3--4-5--6--7";
    TreeNode* root1 = sol.recoverFromPreorder(traversal1);
    printTree(root1);
    cout << endl; 
    
    string traversal2 = "1-2--3---4-5--6---7";
    TreeNode* root2 = sol.recoverFromPreorder(traversal2);
    printTree(root2);
    cout << endl; 
    
    string traversal3 = "1-401--349---90--88";
    TreeNode* root3 = sol.recoverFromPreorder(traversal3);
    printTree(root3);
    cout << endl; 
    
    return 0;
}
