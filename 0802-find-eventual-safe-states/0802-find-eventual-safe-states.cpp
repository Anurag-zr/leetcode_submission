class Solution {
public:
    
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis){
        vis[node]=1;
        vis[node]=2;
        
        for(auto adjNode:graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,graph,vis)==true) return true;
            }
            else if(vis[adjNode]==2){
                return true;
            }
        }
        
        vis[node]=3;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==3) ans.push_back(i);    
        }
        
        return ans;
    }
};