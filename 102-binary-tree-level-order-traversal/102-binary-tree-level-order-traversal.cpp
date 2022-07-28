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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int> level (size);
            for(int i=0;i<size;i++){
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left!=nullptr) queue.push(node->left);
                if(node->right!=nullptr) queue.push(node->right);
                
                level[i] = node->val;
            }
            
            ans.push_back(level);
        }
        
        
        return ans;
    }
};