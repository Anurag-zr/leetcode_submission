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
    
    string create(TreeNode* root){
        if(root==NULL) return "";
        string ans="";
        ans+=to_string(root->val);
        if(root->left || (root->left==NULL && root->right)){
            ans+='(';
            ans+=create(root->left);
            ans+=')';
        }
        
        if(root->right){
          ans+='(';
          ans+=create(root->right);
          ans+=')';
        }
        
        
        return ans;
        
    }
    
    string tree2str(TreeNode* root) {
        
        return create(root);
    }
};