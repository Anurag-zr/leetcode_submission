class Solution {
public:
    
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<int> &markSafeNode,vector<vector<int>> &graph){
        
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto adjNode: graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,vis,pathVis,markSafeNode,graph) == true) return true;
            }
            else if(vis[adjNode] && pathVis[adjNode]){
                return true;
            }
        }
        
        markSafeNode[node] =1;
        pathVis[node]=0;
        
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> markSafeNode(n,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,markSafeNode,graph);
            }
        }
        
        for(int i=0;i<n;i++){
            if(markSafeNode[i]) ans.push_back(i);
        }
        
        
        return ans;
    }
};