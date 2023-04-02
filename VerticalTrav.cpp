#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// The verticalTraversal function returns a 2D vector containing the nodes of the binary
// tree in vertical order. Each vector in the 2D vector represents a vertical line of
// nodes.
vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Create a map where the keys are the horizontal distance from the root node and the
    // values are maps where the keys are the level of the node and the values are multiset
    // of nodes at that level and horizontal distance.
    map<int, map<int, multiset<int>>> m;

    // Create a queue to do a level-order traversal of the binary tree
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    // Traverse the binary tree in level order, keeping track of the horizontal distance
    // and level of each node.
    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int v = it.second.first;  // horizontal distance
        int l = it.second.second; // level

        // Insert the node into the multiset for its horizontal distance and level.
        m[v][l].insert(node->data);

        // Enqueue the left child with a horizontal distance one less than the parent and a
        // level one greater than the parent.
        if (node->left)
            q.push({node->left, {v-1, l+1}});

        // Enqueue the right child with a horizontal distance one greater than the parent and
        // a level one greater than the parent.
        if (node->right)
            q.push({node->right, {v+1, l+1}});
    }

    // Create a 2D vector to hold the result.
    vector<vector<int>> ans;

    // Traverse the map by horizontal distance and level, adding each multiset to a vector,
    // which is then added to the final result.
    for (auto p : m) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    // Return the final result.
    return ans;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Calling verticalTraversal function on the binary tree
    vector<vector<int>> result = verticalTraversal(root);

    // Displaying the result of verticalTraversal function
    for (auto& col : result) {
        for (auto& val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}