
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
     int n = isConnected.size(); //no of nodes
     int cnt = n; // let's assume initally all are individual component;
        
     DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(isConnected[i][j]){ //edge btw u and v
                   int u = i+1;
                   int v = j+1;
                    
                    if(ds.findUParent(u)!=ds.findUParent(v)){
                        ds.unionByRank(u,v);
                        cnt--;
                    }
                 
                }
            }
        }
        
        return cnt;
    }
};