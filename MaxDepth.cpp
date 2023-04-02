#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
     data = val;
        left = right = NULL;
    }
};

int Maxdepth(TreeNode* root){

    if(root == NULL) return 0;

    int left = Maxdepth(root->left);
    int right = Maxdepth(root->right);

    return 1 + max(left, right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

   int result = Maxdepth(root);

   cout<<result;
    }