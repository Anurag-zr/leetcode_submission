class Solution {
public:
    
    void dfs(int node,vector<int> &vis,vector<vector<int>> &isConnected){
        vis[node]=1;
         // add node element here for dfs traversal
        
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 &&  !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        
        int count_proviences =0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,vis,isConnected);
            count_proviences++;
            }
        }
        
        return count_proviences;
    }
};