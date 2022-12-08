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

    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }

    void dfs(TreeNode* node, vector<int> &ds){
        if(node==NULL) return;

        if(isLeaf(node)) ds.push_back(node->val);

        dfs(node->left,ds);
        dfs(node->right,ds);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        dfs(root1,leaves1);
        dfs(root2,leaves2);

        return leaves1==leaves2;
    }
};