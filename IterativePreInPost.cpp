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

vector<int> PreInpost(TreeNode* root){

    vector<int>pre,in,post;

    if(root == NULL) return post;

    stack<pair<TreeNode*, int>>s;

        s.push({root, 0});

        while(!s.empty()){

            auto it = s.top();
            s.pop();

            // This is the part of preorder

            if(it.second == 1){
                pre.push_back(it.first->data);

                it.second++;
            s.push(it);

            if(it.first->left) s.push({it.first->left , 1});

           }

        // This is the part of postorder

           else if(it.second == 2){
                in.push_back(it.first->data);

                it.second++;

            s.push(it);

            if(it.first->right){ s.push({it.first->right , 1});
           }
        }

    else {
        post.push_back(it.first->data);
          }
    }
}


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = PreInpost(root);

        for(auto& val : result){
            cout << val << " ";
        }
        cout << endl;
}
  

