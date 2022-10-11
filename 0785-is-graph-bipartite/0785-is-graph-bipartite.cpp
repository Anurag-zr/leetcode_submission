class Solution {
public:
    
    bool bfs(int start,vector<int> &vis,vector<vector<int>> &graph){
        vis[start]=0; //color 0
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode: graph[node]){
                if(vis[adjNode]==-1) {//not visited
                    vis[adjNode]= !vis[node];
                    q.push(adjNode);
                }
                else if(vis[adjNode] == vis[node]){ //already visited and of same color as parent,then graph is not bipartite
                    return false;
                }
                else{ // visited but of different color as parent then it's okay
                    
                }
            }
        }
        
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vis(n,-1); //intially no color to any node
        
        for(int i =0;i<n;i++){
            if(vis[i]==-1) 
                if(bfs(i,vis,graph)==false) return false;
        }
        
        return true;
    }
};