#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    long long total = 0, best = 0;
    static const int MOD = 1000000007;

    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + dfs(root->left) + dfs(root->right);
        best = max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return best % MOD;
    }
};

TreeNode* buildTree(vector<long long>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];   
    }

    TreeNode* root = buildTree(arr);

    Solution sol;
    cout << sol.maxProduct(root) << endl;

    return 0;
}
