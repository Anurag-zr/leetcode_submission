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
class Solution {
public:
    
    bool find(TreeNode* root,int k,unordered_map<int,TreeNode*> &umap){
        if(root==nullptr) return false;
        if(umap.find(k-root->val)!=umap.end()) return true;
        else{
            umap[root->val]=root;
        }
        
        bool left = find(root->left,k,umap);
        if(left) return true;
        bool right = find(root->right,k,umap);
        if(right) return true;
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        
        unordered_map<int,TreeNode*> umap;
        
        return find(root,k,umap);
    }
};