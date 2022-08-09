/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node =  q.front();
            q.pop();
            
            if(node!=nullptr){
            ans+=to_string(node->val);
            ans+=",";
            }
            else{
                ans+="N,";
            }
            
            
            if(node!=nullptr){
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        
        return ans;
    }
    
    
        // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;

        getline(s, str, ',');
        if(str=="N")
            return nullptr;

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode();
        root->val = stoi(str);
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node= q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="N") node->left = nullptr;
            else{
                TreeNode* leftNode = new TreeNode();
                leftNode->val = stoi(str);
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str=="N") node->right = nullptr;
            else{
                TreeNode* rightNode = new TreeNode();
                rightNode->val =stoi(str);
                node->right = rightNode;
                q.push(rightNode);
            }
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));