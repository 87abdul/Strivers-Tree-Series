/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    unordered_map<int, int>mp; // Stores (node -> index in inorder array)
    
    TreeNode* make_tree(int start, int end, int &idx, vector<int>& postorder, vector<int>& inorder){
        
		// If range for inorder is NOT valid then return NULL
        if(start > end) return NULL;
        
		// Create a node for our root node of current subtree
        TreeNode* root = new TreeNode(postorder[idx]);
        
		// Find position of current root in inorder array
        int i = mp[root->data];
		
		// Decrement our pointer to postorder array for our next upcoming root if any
        idx--;
		
		// Make a call to create right subtree, inorder range [i+1, end]
        root->right = make_tree(i+1, end, idx, postorder, inorder);
		
		// Make a call to create left subtree, inorder range [start, i-1]
        root->left = make_tree(start, i-1, idx, postorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        
		// Create (nodes -> index of inorder array) mapping
        for(int i{}; i<inorder.size(); ++i){
            
            mp[inorder[i]] = i;
        }
		// Create tree starting from root at position (n-1) in postorder array
		// Range for current inirder array : [0, n-1]
        return make_tree(0, inorder.size()-1, idx, postorder, inorder);
    }
};

int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    // Traverse the binary tree in inorder and print its values
    function<void(TreeNode*)> inorder_traversal = [&](TreeNode* node) {
        if(node == nullptr) return;
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    };
    inorder_traversal(root); // Output: 9 3 15 20 7
    return 0;
}