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
    
    TreeNode* addRow(int i,TreeNode* root,int &val,int &depth){
        if(root==NULL) return NULL;
        if(i+1==depth){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
            
            return root;
        }
        
        
        addRow(i+1,root->left,val,depth);
        addRow(i+1,root->right,val,depth);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        return  addRow(1,root,val,depth);
    }
};