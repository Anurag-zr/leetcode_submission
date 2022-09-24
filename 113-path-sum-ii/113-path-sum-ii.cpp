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
    
    void findPathSum(TreeNode* root,int targetSum,vector<int> &ds,vector<vector<int>> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                ds.push_back(root->val);
                targetSum-=root->val;
                ans.push_back(ds);
                targetSum+=root->val;
                ds.pop_back();
            }
            
            return;
        }
        
        
            ds.push_back(root->val);
            targetSum-=root->val;
            
            findPathSum(root->left,targetSum,ds,ans);
            findPathSum(root->right,targetSum,ds,ans);
            
            targetSum+=root->val;
            ds.pop_back();
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        findPathSum(root,targetSum,ds,ans);
        
        return ans;
    }
};