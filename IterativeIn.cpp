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

vector<int> InOrder(TreeNode* root){

    vector<int>in;

    if(root == NULL) return in;

    stack<TreeNode*>s;

    TreeNode* node = root;

    while(true){

        if(node){
                s.push(node);
                
                node = node->left;
          }

          else{
                if(s.empty() == true) break;

                node = s.top();

                    s.pop();
                    in.push_back(node->data);

                    node = node->right;
          }
    }

    return in;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> result = InOrder(root);

        for(auto& val : result){
            cout << val << " ";
        }
        cout << endl;
    }