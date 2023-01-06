//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int r= pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r==n-1 && c==m-1) return dist[r][c];
            
            
            for(int i=0;i<4;i++){
                int nr = r+ dr[i];
                int nc = c+ dc[i];
                
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                
                int newEffort = max(dist[r][c],abs(heights[nr][nc]-heights[r][c]));
                
                if(newEffort< dist[nr][nc]){
                    pq.push({newEffort,{nr,nc}});
                    dist[nr][nc]=newEffort;
                }
            }
            
        }
        
        
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends