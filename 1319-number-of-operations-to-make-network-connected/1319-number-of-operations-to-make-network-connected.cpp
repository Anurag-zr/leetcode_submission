class  DisjointSet{
    public: 
      vector<int> parent;
      vector<int> size;
      
    public:
       
       DisjointSet(int n){
           parent.resize(n+1);
           size.resize(n+1,1);
           
           for(int i=0;i<=n;i++) parent[i]=i;
       }
       
       
       int findUParent(int u){
           if(parent[u]==u) return u;
           
           return parent[u] = findUParent(parent[u]);
       }
       
       void unionBySize(int u,int v){
           int upu = findUParent(u);
           int upv = findUParent(v);
           
           if(upu==upv) return;
           
           if(size[upu]< size[upv]){
               parent[upu]= upv;
               size[upv]+=size[upu];
           }
           
           if(size[upv]<=size[upu]){
               parent[upv]=upu;
               size[upu]+=size[upv];
           }
       }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numCable = connections.size();
        
        if(numCable+1<n) return -1;
        
        DisjointSet ds(n);
        
        int numComponent =n;
        for(auto it: connections){
            int u=it[0];
            int v = it[1];
            
            if(ds.findUParent(u)==ds.findUParent(v)) continue;
            
            ds.unionBySize(u,v);
            numComponent--;
        }
        
        return numComponent-1;
    }
};