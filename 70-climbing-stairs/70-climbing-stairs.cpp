class Solution {
public:
    
    int countWays(int n,vector<int> &dp){
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int l = countWays(n-1,dp);
        int r=0;
        if(n-2>=0)
            r=countWays(n-2,dp);
        
        return dp[n]=l+r;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return countWays(n,dp);
    }
};