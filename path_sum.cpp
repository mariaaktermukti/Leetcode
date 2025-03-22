#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    targetSum -= root->val;

    if (!root->left && !root->right) {
        return targetSum == 0;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

TreeNode* insertLevelOrder(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);

    return root;
}

int main() {
    int n, targetSum;
    cout << "Enter number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter tree nodes (use -1 for null nodes): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> targetSum;

    TreeNode* root = insertLevelOrder(arr, 0, n);
    bool result = hasPathSum(root, targetSum);

    cout << (result ? "True" : "False") << endl;

    return 0;
}
