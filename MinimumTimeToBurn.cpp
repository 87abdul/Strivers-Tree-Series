#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*>& mp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        map<TreeNode*, bool> vis;
        while(!q.empty()) {
            TreeNode* node = q.front();
            if(node->data == start) res = node;
            q.pop();
            if(node->left) {
                mp[node->left] = node;
                q.push(node->left);
                vis[node->left] = false;
            }
            if(node->right) {
                mp[node->right] = node;
                q.push(node->right);
                vis[node->right] = false;
            }
        }
        return res;
    }

    int findMaxDistance(map<TreeNode*, TreeNode*>& mp, TreeNode* target) {
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        map<TreeNode*, bool> vis;
        vis[target] = true;
        int maxi = 0;
        while(!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            maxi = max(maxi, depth);
            if(node->left && !vis[node->left]) {
                vis[node->left] = true;
                q.push({node->left, depth+1});
            }
            if(node->right && !vis[node->right]) {
                vis[node->right] = true;
                q.push({node->right, depth+1});
            }
            if(mp[node] && !vis[mp[node]]) {
                vis[mp[node]] = true;
                q.push({mp[node], depth+1});
            }
        }
        return maxi;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;
        TreeNode* target = bfsToMapParents(root, mp, start);
        int maxi = findMaxDistance(mp, target);
        return maxi;
    }
};

int main() {
    // create sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    int start = 5;
    int res = sol.amountOfTime(root, start);
    cout << res << endl; // should output 3

    return 0;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


