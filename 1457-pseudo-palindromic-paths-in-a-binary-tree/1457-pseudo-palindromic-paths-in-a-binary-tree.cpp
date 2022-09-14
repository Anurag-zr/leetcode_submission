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
            unordered_map<int,int> umap;
            int ans=0;
public:
    
    void findPossiblePath(TreeNode* root){
        if(root==NULL) return;
        
            umap[root->val]++;
        
        
        if( !root->left && !root->right){ //leaf node
            int odd =0;
            for(auto a:umap){
                if(a.second%2==1) odd++;
            }
            
            if(odd<=1) ans++;
            
        }
        
         findPossiblePath(root->left);
        findPossiblePath(root->right);
        
        umap[root->val]--;
          
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
         findPossiblePath(root);
        return ans;
    }
    
    
};