class Solution {
public:
    
    vector<long long> dfs(int node,int parent,vector<int> adjList[],int &seats){
        long long fuelCost,ambassador;
        fuelCost =0;
        ambassador =1;
        int cars=0;
        
        for(auto adjNode: adjList[node]){
            if(adjNode == parent) continue;
            
            vector<long long> temp = dfs(adjNode,node,adjList,seats);
            fuelCost+=temp[0];
            ambassador+= temp[1];
        }

        cars = ceil((double)ambassador/seats);
        fuelCost += cars*1;
        
        return {fuelCost,ambassador};
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adjList[n+1];
        
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        long long ans=0;
        
        for(auto adjNode : adjList[0]){
           vector<long long> temp = dfs(adjNode,0,adjList,seats);
            ans+=temp[0];
        }
        
      return ans;    
    }
};