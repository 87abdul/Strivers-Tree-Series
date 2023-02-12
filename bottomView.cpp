class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        // line -2(root->left->left), -1(root->left), 0(root), 1(root->right) 2(root->right->right)
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root,0}); // line 0 the root will be inserted
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
           // if(mp.find(line) == mp.end())
            mp[line] = node->data;
            
            if(node->left !=NULL){
                q.push({node->left, line-1});
            }
            
            if(node->right !=NULL){
                q.push({node->right, line+1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
