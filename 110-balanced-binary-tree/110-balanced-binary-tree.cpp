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
    
    int findheight(TreeNode* node){
        if(node==nullptr) return 0;
        
        int lh = findheight(node->left);
        int rh = findheight(node->right);
        
        return 1+ max(lh,rh);
    }
    
    bool check(TreeNode* node){
        if(node == nullptr) return true;
        
        int lh = findheight(node->left);
        int rh = findheight(node->right);
        
        if(abs(lh-rh)>1) return false;
        
        if(check(node->left)==false || check(node->right)==false) return false;
        
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
      return check(root);
    }
};