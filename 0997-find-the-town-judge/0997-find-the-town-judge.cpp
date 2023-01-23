class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        vector<int> indegree(n+1,0);
        
        for(auto it: trust){
            int u = it[0];
            int v = it[1];

            indegree[v]++;
            adj[u].push_back(v);
        }
        
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && adj[i].size()==0){
                return i;
            }
            
            
        }
        
        return -1;
    }
};