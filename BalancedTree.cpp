#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

int CheckBalancedTree(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = CheckBalancedTree(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = CheckBalancedTree(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(10);
    // root->right->left->left = new TreeNode(11);
    // root->right->left->left->left = new TreeNode(14);
    // root->right->left->left->left->left = new TreeNode(19);

    int result = CheckBalancedTree(root);

    if (result == -1)
        cout << "Not balanced";
    else
        cout << "Balanced tree";

    return 0;
}