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
     void Path(TreeNode* node,int &ds_sum,vector<int> &ans){
     if(node==nullptr) return;
     
     if(node->left==nullptr && node->right == nullptr){ 
        ds_sum= 10*ds_sum +(node->val);
        ans.push_back(ds_sum);  
        ds_sum-=node->val;
        ds_sum/=10;
    
         return;
     }
     
     ds_sum= 10*ds_sum +(node->val);
     Path(node->left,ds_sum,ans);
     Path(node->right,ds_sum,ans);
     ds_sum-=node->val;
     ds_sum/=10;
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