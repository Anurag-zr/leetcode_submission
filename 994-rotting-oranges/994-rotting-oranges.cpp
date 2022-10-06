class Solution {
public:
    
    int bfs(queue<pair<int,int>> &q,vector<int> &dx,vector<int> &dy,int &freshOrgCnt,vector<vector<int>> &grid){
        
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                
                q.pop();
                
                for(int j = 0;j<4;j++){
                    int nr = r+dx[j];
                    int nc = c+dy[j];
                    
                    if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        freshOrgCnt--;
                        q.push({nr,nc});
                        flag =true;
                    }
                    
                }
                
            }
            
            
            if(flag) time++;
        }
        
        return time;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        int freshOrgCnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) freshOrgCnt++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        int ans =0;
        vector<int> dx ={-1,0,+1,0};
        vector<int> dy ={0,+1,0,-1};
        
         ans =bfs(q,dx,dy,freshOrgCnt,grid);
        
        
        if(freshOrgCnt!=0) return -1;
        
        return ans;
        
    }
};