/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> ds;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size= q.size();
            
            for(int i=0;i<size;i++){
                Node* cur = q.front();
                q.pop();
                
                int no_child = cur->children.size();
                
                for(int j=0;j<no_child;j++){
                    
                     q.push(cur->children[j]);
                }
                
                ds.push_back(cur->val);
            }
            
            ans.push_back(ds);
            ds.clear();
        }
        
        
        return ans;
    }
};