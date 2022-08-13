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
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL) return INT_MAX;
        int l= kthSmallest(root->left,k);
        if(l!=INT_MAX) return l;
        k--;
        
         if(k==0) return root->val;
        int r=kthSmallest(root->right,k);
        
        return r;
    }
};