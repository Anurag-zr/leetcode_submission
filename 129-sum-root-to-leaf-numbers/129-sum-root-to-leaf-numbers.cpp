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
    
 void Path(TreeNode* node,int ds_sum,vector<int> &ans){
     if(node==nullptr) return;
     
     if(node->left==nullptr && node->right == nullptr){ 
        ans.push_back(ds_sum*10+node->val);  
         return;
     }
     
     Path(node->left, ds_sum*10 + (node->val),ans);
     Path(node->right, ds_sum*10 + (node->val),ans);
 }
    
    int sumNumbers(TreeNode* root) {
      int ds_sum=0;
      vector<int> ans;
        Path(root,ds_sum,ans);
        
        int sum=0;
        for(auto i:ans){
            sum+=i;
        }
        
        return sum;
    }
};