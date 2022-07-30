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
    
//     void inorder(TreeNode* node,vector<int> &ans){
//         if(node == nullptr) return;
//         inorder(node->left,ans);
//         ans.push_back(node->val);
//         inorder(node->right,ans);
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root==nullptr) return {};
//         vector<int> ans;
//         inorder(root,ans);
//         return ans;
//     }
    
      vector<int> inorderTraversal(TreeNode* root){
            if(root==nullptr) return {};
            vector<int> ans;
            stack<TreeNode *> st;
            TreeNode *node = root;
            while(true){
                if(node!=nullptr){
                    st.push(node);
                    node = node->left;
                }
                else{
                    if(st.empty()==true)
                        break;

                    node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    node = node->right;
                }
            }


            return ans;
     }
};