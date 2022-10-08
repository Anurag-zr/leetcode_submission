class Solution {
public:
    
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<char>> &board){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || vis[r][c] || board[r][c]=='X') return;
        
        vis[r][c]=1;
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c+ dc[i];
            
            dfs(nr,nc,vis,board);
            
        }
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        //traverse first and last row
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,board);
            }
            
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board);
            }
        }
        
        //traverse first and last col
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,board);
            }
            
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};