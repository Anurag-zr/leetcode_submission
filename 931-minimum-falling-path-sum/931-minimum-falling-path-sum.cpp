class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){

       if(j<0 || j>grid.size()-1){
            return 1e9;
        }
        
        if(i==0){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int diaL = grid[i][j] + f(i-1,j-1,grid,dp);
        int diaR = grid[i][j] + f(i-1,j+1,grid,dp);
        
        return dp[i][j] = min(up,min(diaL,diaR));
    
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<int> ans;
        
        for(int j=0;j<n;j++){
            vector<vector<int>> dp(n,vector<int> (n,-1));
            ans.push_back(f(n-1,j,matrix,dp));
        }
        
        return *min_element(ans.begin(),ans.end());
    }
};