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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        int width=0;
        q.push({root,0});
        while(!q.empty()){
          int size = q.size();
          int first,last;
          int min_ind = q.front().second;
          for(int i=0;i<size;i++){
              int cur_ind = q.front().second - min_ind;
              TreeNode* node = q.front().first;
              q.pop();
              if(i==0) first = cur_ind;
              if(i==size-1) last = cur_ind;
              if(node->left!=nullptr) q.push({node->left,(long long) cur_ind*2+1});
              if(node->right!=nullptr) q.push({node->right,(long long) 2*cur_ind+2});
          }
            
            width = max(width,last-first+1);
        }
        
        return width;
    }
};