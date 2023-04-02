#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int MaxPathDown(TreeNode *node, int &maxi)
{
    // Check if the current node is null
    if (!node)
    {
        return 0;
    }
    // Recursively compute the maximum path sum starting from the left child,
    // and take the maximum of 0 and its value
    int leftSum = max(0, MaxPathDown(node->left, maxi));
    // Recursively compute the maximum path sum starting from the right child,
    // and take the maximum of 0 and its value
    int rightSum = max(0, MaxPathDown(node->right, maxi));
    // Update the global maximum path sum by adding the value of the current node
    // and the maximum path sums of its left and right children
    maxi = max(maxi, leftSum + rightSum + node->data);
    // Return the maximum path sum between the left and right subtrees of the current node,
    // plus the value of the current node
    return max(leftSum, rightSum) + node->data;
}
int MaxPathSum(TreeNode *node)
{

    int maxi = INT_MIN;

    MaxPathDown(node, maxi);
    return maxi;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    // root->right->left->left = new TreeNode(5);
    // root->right->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(8);
    // root->right->right->right->right = new TreeNode(9);

    int result = MaxPathSum(root);

    cout << result;
}

/*Working
Sure, here's an example to explain how the
MaxPathDown
 function works:

Suppose we have the following binary tree:

      10
     /  \
    2    10
   / \     \
 20   1    -25
          /  \
         3    4
We want to find the maximum path sum starting from any node and going down towards the leaves of the tree.

First, we call the
MaxPathDown
 function with the root node
10 and initialize maxi to be -∞

int maxi = INT_MIN;
int maxPathSum = MaxPathDown(root, maxi);
The first line initializes
maxi
 to be the smallest possible integer value, since we want to find the maximum path sum in the tree. The second line calls the
MaxPathDown
 function with the root node and the reference to
maxi
, which will be used to update the global maximum path sum as we traverse the tree.

At the root node
10
, we compute the maximum path sums starting from the left and right children recursively:

int leftSum = MaxPathDown(node->left, maxi);  // returns 22
int rightSum = MaxPathDown(node->right, maxi);  // returns 10
For the left child
2
, we compute the maximum path sums starting from its subchildren recursively:

int leftSum = MaxPathDown(node->left, maxi);  // returns 20
int rightSum = MaxPathDown(node->right, maxi);  // returns 1
Since both
leftSum
 and
rightSum
 are positive, we update the global maximum path sum:

 maxi = max(maxi, leftSum + rightSum + node->data);  // maxi is now 33
We return the maximum path sum between the left and right subtrees of the current node, plus the value of the current node:

return max(leftSum, rightSum) + node->data;  // returns 22 + 10 = 32
This value is then used to compute the maximum path sums of the parent nodes recursively, until we reach the root.

At the end of the function,
maxi
 contains the maximum path sum in the tree, which is
33
, computed from the path
20 -> 2 -> 10 -> -25 -> 3
*/