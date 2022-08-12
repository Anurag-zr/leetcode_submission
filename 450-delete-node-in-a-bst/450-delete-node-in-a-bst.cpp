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
    
    TreeNode* findMax(TreeNode *node){
        if(node->right == NULL){
            return node;
        }
        
        return findMax(node->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left ==NULL) return root->right;
            if(root->right == NULL) return root->left;
            else{
                TreeNode* maxLeft = findMax(root->left);
                root->val = maxLeft->val;
                root->left = deleteNode(root->left,root->val);
                return root;
            }
        }
        
        if(key<root->val){
           root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        
        
        return root;
    }
};