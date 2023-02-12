class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
 vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()){
            
            auto a = q.front();
            q.pop();
            Node* curr = a.first;
            int val = a.second;
            mp[val].push_back(curr->data);
            
            if(curr->left)q.push({curr->left, val-1});
            if(curr->right)q.push({curr->right, val+1});
        }
        vector<int> res;
       
        for(auto it: mp){
            
             vector<int> ans = it.second;
             for(auto ti : ans){
                 res.push_back(ti);
             }
            
        }
        
        return res;
        
    }
};

