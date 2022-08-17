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
    private:
    TreeNode *prev;
    TreeNode *first;
    TreeNode *mid;
    TreeNode *last;
    
    
    void inorder(TreeNode* node){
        if(node==nullptr) return;
        
        inorder(node->left);
        if(prev!=nullptr && prev->val>node->val){
            if(first==nullptr){//1st violation
                first = prev;
                mid = node;
            }
            else{
                last = node;
            }
        }
        prev=node;
        inorder(node->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
      first=mid=last=prev=nullptr;
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else swap(first->val,mid->val);
    }
};