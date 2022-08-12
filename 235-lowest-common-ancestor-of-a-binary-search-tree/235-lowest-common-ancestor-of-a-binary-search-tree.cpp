/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root ==q) return root;
        
        if(p->val<root->val && q->val<root->val){
          TreeNode* left = lowestCommonAncestor(root->left,p,q);
            return left;
        }
        else if(p->val>root->val && q->val>root->val){
          TreeNode* right = lowestCommonAncestor(root->right,p,q);
            return right;
        }
        
        else return root;
    }
};