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
     void Path(TreeNode* node,vector<int> &ds,vector<int> &ans){
     if(node==nullptr) return;
     
     if(node->left==nullptr && node->right == nullptr){ 
         ds.push_back(node->val);
         long base =1;
         int num =0;
         for(int i = ds.size()-1;i>=0;i--){
             num+=base*ds[i];
             base = base*10;
         }
        ans.push_back(num);   
        ds.pop_back();
         return;
     }
     
     ds.push_back(node->val);
     Path(node->left,ds,ans);
     Path(node->right,ds,ans);
     ds.pop_back();
 }
    
    int sumNumbers(TreeNode* root) {
      vector<int> ds;
      vector<int> ans;
        Path(root,ds,ans);
        
        int sum=0;
        for(auto i:ans){
            sum+=i;
        }
        
        return sum;
    }
};