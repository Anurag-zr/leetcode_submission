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
    
    void reversePreorder(TreeNode* node,int level,vector<int> &ans){
        if(node == NULL) return;
        
        if(level == ans.size()) ans.push_back(node->val);
        reversePreorder(node->right,level+1,ans);
        reversePreorder(node->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        reversePreorder(root,0,ans);
        return ans;
    }
};