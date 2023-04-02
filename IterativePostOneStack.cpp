#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;

    stack<Node*> stk;
    Node* cur = root;
    Node* prev = NULL;

// Traverse the binary tree using a stack
while (cur || !stk.empty()) {
    // Traverse all the way to the left subtree and push each node onto the stack
    if (cur) {
        stk.push(cur);
        cur = cur->left;
    } else { 
        // When there are no more nodes to the left, start processing from the top of the stack
        Node* topNode = stk.top();
        // If the right subtree is empty or has already been processed, visit the current node
        if (!topNode->right || topNode->right == prev) {
            res.push_back(topNode->val); // visit
            prev = topNode;
            stk.pop();
        } else { 
            // If the right subtree exists and hasn't been processed yet, traverse the right subtree
            cur = topNode->right;
        }
    }
}

    return res;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<int> result = postorderTraversal(root);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;

    delete root;
    return 0;
}