//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto adjNode:adj[i]){
                indegree[adjNode]++;
            }
        }
        
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int topoSize = 0;
        while(!q.empty()){
           int node = q.front();
           q.pop();
           topoSize++;
           
           for(auto adjNode: adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode]==0) q.push(adjNode);
           }
        }
        
        
        if(topoSize == V) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends