//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[src.first][src.second]=0;
        vector<int> dx ={-1,0,1,0};
        vector<int> dy ={0,1,0,-1};
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src.first,src.second}});
        
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = r+ dx[i];
                int nc = c + dy[i];
                  
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(grid[nr][nc]==1 && dist[r][c]+1<dist[nr][nc]){
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        

        
        
        if(dist[dest.first][dest.second]==1e9) return -1;
        
        return dist[dest.first][dest.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends