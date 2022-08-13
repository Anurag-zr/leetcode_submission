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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind =0;
        return buildTree(preorder,ind,INT_MAX);
    }
    
    TreeNode* buildTree(vector<int> &pre,int &ind,int bound){
        if(ind>=pre.size() || pre[ind]>bound) return nullptr;
        
        TreeNode* root = new TreeNode(pre[ind]);
        ind++;
        root->left = buildTree(pre,ind,root->val);
        root->right = buildTree(pre,ind,bound);
        
        return root;
    }
};