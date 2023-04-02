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

void addLeftBoundary(TreeNode* root, vector<int> &res){
    if(!root) return;

    if(root->left || root->right){
        res.push_back(root->data);
    }

    if(root->left){
        addLeftBoundary(root->left, res);
    }else if(root->right){
        addLeftBoundary(root->right, res);
    }
}

void addRightBoundary(TreeNode* root, vector<int> &res){
    if(!root) return;

    if(root->left || root->right){
        res.push_back(root->data);
    }

    if(root->right){
        addRightBoundary(root->right, res);
    }else if(root->left){
        addRightBoundary(root->left, res);
    }
}

void addLeaves(TreeNode* root, vector<int> &res){
    if(!root) return;

    if(!root->left && !root->right){ //leaf node
        res.push_back(root->data);
    }

    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

vector<int>BoundaryTraversal(TreeNode* root){
    vector<int>result;

    if(root == NULL) return result;

    result.push_back(root->data);

    addLeftBoundary(root->left, result);
    addLeaves(root, result);
    addRightBoundary(root->right, result);

    return result;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = BoundaryTraversal(root);

    for(auto& level : result){
        cout<<level<< " ";
    }
    cout << endl;

    return 0;
}