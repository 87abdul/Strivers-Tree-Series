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

vector<int> PostOrder(TreeNode* root){

    vector<int>post;

    if(root == NULL) return post;

    stack<TreeNode*>s1,s2;

        s1.push(root);

    while(!s1.empty()){

            TreeNode* node = s1.top();
                s1.pop();

                s2.push(node);

                if(node->left) s1.push(node->left);
                if(node->right) s1.push(node->right);    

    }

        while(!s2.empty()){
            TreeNode* node = s2.top();
                s2.pop();
            post.push_back(node->data);
        }
        reverse(post.begin(), post.end());
    return post;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = PostOrder(root);

        for(auto& val : result){
            cout << val << " ";
        }
        cout << endl;
    }