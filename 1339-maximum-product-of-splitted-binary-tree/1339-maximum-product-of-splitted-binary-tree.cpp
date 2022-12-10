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
    void calcTotalSum(TreeNode* node,long long &totalSum){
        if(node==NULL) return;
        totalSum+=node->val;
        calcTotalSum(node->left,totalSum);
        calcTotalSum(node->right,totalSum);
    }
    
    int helper(TreeNode* node,long long &totalSum,long long &maxiProduct){
        if(node==NULL) return 0;
        
        int lh = helper(node->left,totalSum,maxiProduct);
        int rh = helper(node->right,totalSum, maxiProduct);
        
        maxiProduct = max(maxiProduct,lh*(totalSum-lh));
        maxiProduct = max(maxiProduct,rh*(totalSum-rh));
        
        // cout<<node->val<<" "<<totalSum<<" "<<lh<<" "<<rh<<" "<<maxiProduct<<endl;
        
        return node->val+lh+rh;
    }
    
    int maxProduct(TreeNode* root) {
        long long totalSum =0;
        long long maxiProduct = INT_MIN;
        calcTotalSum(root,totalSum);
        helper(root,totalSum,maxiProduct);
        
        return maxiProduct % (int)(1e9 +7);
    }
};