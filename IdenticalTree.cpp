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

    bool CheckIdentical( TreeNode* p, TreeNode* q) {

        if ( p == NULL || q == NULL) {
            return p == q;
        }

        if(p->data != q->data) return false;

        return CheckIdentical(p->left, q->left) && CheckIdentical(p->right, q->right);

    }


int main(){
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->right->left = new TreeNode(4);
    p->right->left->left = new TreeNode(5);
    p->right->left->left->left = new TreeNode(6);
    p->right->right = new TreeNode(7);
    p->right->right->right = new TreeNode(8);
    // p->right->right->right->right = new TreeNode(9);


    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->right->left = new TreeNode(4);
    q->right->left->left = new TreeNode(5);
    q->right->left->left->left = new TreeNode(6);
    q->right->right = new TreeNode(7);
    q->right->right->right = new TreeNode(8);
    // q->right->right->right->right = new TreeNode(9);

   bool result = CheckIdentical(p,q);

   if(result == false){
    cout<<"Not same tree";
   } 

   else{
    cout<<"Same tree";
   }
}