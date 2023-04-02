#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


int Ceil(TreeNode* root, int key){

    int ceil = -1;

    while(root){

        if(root->data == key){
            ceil = root->data;
            return ceil;
        }

        if(root->data > key){

            root = root->right;
        }

        else{
            ceil = root->data;
            root= root->left;
        }
    }


    return ceil;
}




