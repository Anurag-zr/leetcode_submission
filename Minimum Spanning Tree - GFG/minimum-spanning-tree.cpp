//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    private:
    vector<int> rank;  //for union by rank
    vector<int> parent;
    // vector<int> size;  //for union by size

    public:
     DisjointSet(int n){
        rank.resize(n+1,0);  //for 1 based indexing of graph
        parent.resize(n + 1);
        // size.resize(n+1,1);    

        for (int i = 0; i < n + 1;i++){
            parent[i] = i;
            // size[i] = 1;
        }
     }


     int findUParent(int u){
        if(parent[u]==u)
            return u;

        return parent[u] = findUParent(parent[u]);
     }

     void unionByRank(int u,int v){
        int upu = findUParent(u);
        int upv = findUParent(v);

        if(upu==upv)
            return;

        if(rank[upu]<rank[upv]){
            parent[upu] = upv;
        }
        else if(rank[upv]<rank[upu]){
            parent[upv] = upu;
        }
        else{ // rank[upu]==rank[upv]
            parent[upv] = upu;
            rank[upu]++;
        }
     }
};

typedef pair<int,int> pii;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pii>> edges;
        
        for(int i=0;i<V;i++)
        for(auto it: adj[i]){
            int v = it[0];
            int ew = it[1];
            
            edges.push_back({ew,{i,v}});
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        
        int mstSum =0;
        
        for(auto it :edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUParent(u)!=ds.findUParent(v)){
                mstSum+=wt;
                ds.unionByRank(u,v);
            }
            
        }
        
        return mstSum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends