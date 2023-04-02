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

vector<int> PreOrder(TreeNode* root){

    vector<int>pre;

    if(root == NULL) return pre;

    stack<TreeNode*>s;

    s.push(root);

    while(!s.empty()){

            TreeNode* node = s.top();
            s.pop();

            pre.push_back(node->data);

            if(node->right) s.push(node->right);

            if(node->left) s.push(node->left);
        }

    return pre;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = PreOrder(root);

        for(auto& val : result){
            cout << val << " ";
        }
        cout << endl;
    }