class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &vis,int &initColor,vector<int> &dx,vector<int> &dy,int &color){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !vis[i][j] && grid[i][j]==initColor){
            vis[i][j]=1;
            grid[i][j] = color;
            
            for(int k=0;k<4;k++){
                int nx = i +dx[k];
                int ny = j+dy[k];
                
                dfs(grid,nx,ny,vis,initColor,dx,dy,color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        int initColor = image[sr][sc];
        
        vector<int> dx= {-1,0,+1,0};
        vector<int> dy ={ 0,+1,0,-1};
        
        dfs(image,sr,sc,vis,initColor,dx,dy,color);
        
        
        return image;
    }
};