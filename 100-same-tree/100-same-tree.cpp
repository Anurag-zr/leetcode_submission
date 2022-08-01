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
    
    bool isSame(TreeNode* p,TreeNode* q){
       if(p==nullptr || q==nullptr)  return(p==q);        
        
        bool left = isSame(p->left,q->left);
        bool right = isSame(p->right,q->right);
        
        if(p->val==q->val && left==true && right==true) return true;
        
        return false;
        
          // if (p == NULL || q == NULL) return (p == q);
          // return (p->val == q->val && isSame(p->left, q->left) && isSame(p->right, q->right));
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};