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


    void Preorder(TreeNode* root){
        if(root == NULL) return;

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
        void Inorder(TreeNode* root){
        if(root == NULL) return;

         Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

        void Postorder(TreeNode* root){
        if(root == NULL) return;

        Postorder(root->left);
        Postorder(root->right);
         cout<<root->data<<" ";
    }
    int main(){

        TreeNode* root = new TreeNode(1);

        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        cout<<" Recursive preorder traversal of the given tree : ";
        Preorder(root);

        cout<<"\n Recursive Inorder Traversal of the given tree : "; 
        Inorder(root);

        cout<<"\n Recursive Inorder Traversal of the given tree : "; 
        Postorder(root);
        
    }