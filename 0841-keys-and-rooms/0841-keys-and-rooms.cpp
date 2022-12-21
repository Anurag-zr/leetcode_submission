class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &rooms,vector<int> &vis){
        for(auto adjRoom : rooms[node]){
            if(!vis[adjRoom]){
                vis[adjRoom]=1;
                dfs(adjRoom,rooms,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<int> vis(n,0);
        int start=0;
        vis[start]=1;
            
        dfs(start,rooms,vis);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        
        return true;
    }
};