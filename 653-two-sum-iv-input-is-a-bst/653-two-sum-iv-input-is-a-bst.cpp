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
    
    bool targetExist(TreeNode* root,int k, unordered_map<int,int> &umap){
        if(root==NULL) return false;
        if(umap.find(k-root->val)!=umap.end()) return true;
        
        umap[root->val]=1;
        
        if(targetExist(root->left,k,umap)) return true;
        if(targetExist(root->right,k,umap)) return true;
        
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> umap;
        
        return targetExist(root,k,umap);
    }
};