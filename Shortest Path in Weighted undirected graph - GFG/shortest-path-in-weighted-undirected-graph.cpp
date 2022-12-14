//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adjList[n+1];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        
        vector<int> dist(n+1,1e9),parent(n+1);
        dist[1] = 0;
        
        for(int i=0;i<n+1;i++) parent[i]=i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adjList[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                
                if(dist[node]+edgWt< dist[adjNode]){
                    dist[adjNode]= dist[node]+edgWt;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node]!=node){
            path.push_back(node);
            node =parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends