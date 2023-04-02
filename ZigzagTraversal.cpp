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

vector<vector<int>> SpiralTraversal(TreeNode* root){

    vector<vector<int>>spt;

    if(root == NULL) return spt;

    queue<TreeNode*>q;

    q.push(root);

    bool leftToright = true;

    while(!q.empty()){

        int size = q.size();
        vector<int>row(size);

        for(int i = 0 ;i < size; i++){
            TreeNode* node = q.front();

            q.pop();

            // Find position to store the data

            int index = (leftToright) ? i : (size - i - 1);

            row[index] = node->data;

            // level.push_back(node->data);

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);

            // After every level , we will change the orientation
        }
            leftToright = !leftToright;
            spt.push_back(row);
    }

    return spt;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = SpiralTraversal(root);

    for(auto& level : result){
        for(auto& val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}