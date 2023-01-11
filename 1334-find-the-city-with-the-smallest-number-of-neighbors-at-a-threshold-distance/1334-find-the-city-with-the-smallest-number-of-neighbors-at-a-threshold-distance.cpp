class Solution {
public:
 void dijkstra(int src,vector<pair<int,int>> adjList[],vector<vector<int>> &dist){
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      
      pq.push({0,src});
      
      while(!pq.empty()){
          int node =  pq.top().second;
          int cost = pq.top().first;
          pq.pop();
          
          
          for(auto it: adjList[node]){
              int adjNode = it.first;
              int ew = it.second;
              
              if(cost + ew < dist[src][adjNode]){
                  dist[src][adjNode] = cost + ew;
                  pq.push({cost+ew,adjNode});
              }
          }
      }
  }
  
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
                
        vector<pair<int,int>> adjList[n];
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int d= it[2];
            
            adjList[u].push_back({v,d});
            adjList[v].push_back({u,d});
        }
        
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        for(int i=0;i<n;i++){
          dist[i][i]= 0;
          dijkstra(i,adjList,dist);
        } 
        
        int mini = 1e9;
        int ans;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            
            if(cnt<=mini){mini = cnt, ans = i;}
        }
        
                     
        return ans;   
    }
};