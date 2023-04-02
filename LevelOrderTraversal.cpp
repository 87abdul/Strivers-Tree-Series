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

vector<vector<int>> levelOrder(TreeNode* root){

    vector<vector<int>>bfs;

    if(root == NULL) return bfs;

    queue<TreeNode*>q;

    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int>level;
        for(int i = 0 ;i < size; i++){
            TreeNode* node = q.front();

            q.pop();

            level.push_back(node->data);

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);
        }

        bfs.push_back(level);
    }

    return bfs;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);

    for(auto& level : result){
        for(auto& val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}