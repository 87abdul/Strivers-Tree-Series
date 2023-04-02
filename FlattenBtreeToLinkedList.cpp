/**
 * Definition for a binary tree node.
 */

#include<bits/stdc++.h>

    using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;

        function<void(TreeNode*)> solve = [&](TreeNode* node) {
            if (!node) return;
            solve(node->right);
            solve(node->left);
            node->right = prev;
            node->left = nullptr;
            prev = node;
        };

        solve(root);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root);

    cout << "Flattened tree values: ";
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;

    return 0;
}

