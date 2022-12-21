class Solution {
public:
    
    bool dfs(int node,int &dest,vector<int> adjList[],vector<int> &vis){
        if(node == dest) return true;
        
         for(auto adjNode: adjList[node]){
             if(!vis[adjNode]){
                 vis[adjNode]=1;
             if(dfs(adjNode,dest,adjList,vis)==true) return true;
             }
         }
        
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjList[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n,0);
        vis[source]=1;
     return  dfs(source,destination,adjList,vis);
    }
};