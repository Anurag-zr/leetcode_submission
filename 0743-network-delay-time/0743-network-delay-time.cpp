class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       //classic dijkstra's solution
        
       //step 1. create adjency list
        vector<pair<int,int>> adjList[n+1];
        for(auto it: times){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            
            adjList[u].push_back({v,wt});
        }
        
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        
        while(!pq.empty()){
            int nodeDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adjList[node]){
                int adjNodeWt= it.second;
                int adjNode = it.first;
                
                if(nodeDis+ adjNodeWt < dist[adjNode]){
                    dist[adjNode] = nodeDis + adjNodeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==1e9?-1:ans;
    }
};