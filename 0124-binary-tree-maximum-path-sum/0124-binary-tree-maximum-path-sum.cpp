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
    
    int helper(TreeNode* node,int &maxSum){
        if(node==NULL) return 0;
        
        int lh = helper(node->left,maxSum);
        int rh = helper(node->right,maxSum);
        
        maxSum = max(maxSum,node->val+lh+rh);
        
        if(node->val+lh<0 && node->val+rh<0) return 0;
        else
            return max(node->val+lh,node->val+rh);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        helper(root,maxSum);
        
        return maxSum;
    }
};