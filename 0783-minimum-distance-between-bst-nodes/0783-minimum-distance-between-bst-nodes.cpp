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
    
    void Inorder(TreeNode* root,int &pre,int &mini){
        if(root==nullptr) return;
        
        
        Inorder(root->left,pre,mini);
        
        // cout<<root->val<<" "<<pre<<endl;
        
        mini = min(mini,abs(root->val - pre));
        pre= root->val;
        Inorder(root->right,pre,mini);
    }
    
    int minDiffInBST(TreeNode* root) {
        int pre = 1e9;
        int ans=1e9;
        Inorder(root,pre,ans);
        return ans;
    }
};