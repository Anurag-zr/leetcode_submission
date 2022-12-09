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
    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }
    
    pair<int,int> helperFunction(TreeNode* node,int &maxDiff){
     if(node==NULL) return {1e9,-1e9};
     if(isLeaf(node)) return {node->val,node->val};
        
        pair<int,int> lh = helperFunction(node->left,maxDiff);
        pair<int,int> rh = helperFunction(node->right,maxDiff);
        
        if(lh.first!=1e9){ 
            maxDiff = max(maxDiff,abs(node->val - lh.first));
            maxDiff = max(maxDiff,abs(node->val - lh.second));
        }
        if(rh.first!=1e9){
            maxDiff = max(maxDiff,abs(node->val - rh.first));
            maxDiff = max(maxDiff,abs(node->val - rh.second));
        }
        
        int mini = min(node->val,min(lh.first,rh.first));
        int maxi = max(node->val,max(lh.second,rh.second));
        
        return {mini,maxi};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff=INT_MIN;
        helperFunction(root,maxDiff);
        
        return maxDiff;
    }
};