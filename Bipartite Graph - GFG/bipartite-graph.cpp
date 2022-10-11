//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool dfs(int node,int colr,vector<int> &color,vector<int> adj[]){
        color[node] = colr;
        
        for(auto adjNode: adj[node]){
            if(color[adjNode]==-1){ // if not already visited
                if(dfs(adjNode,!colr,color,adj) == false) return false;
            }
            else if(color[adjNode] == color[node]){ // if already visited and same color as parent
            // then not bipartite graph
                
                return false;
            }
        }
        
        return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1); // not colored
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            int colr =0;
	            if(dfs(i,colr,color,adj)==false)return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends