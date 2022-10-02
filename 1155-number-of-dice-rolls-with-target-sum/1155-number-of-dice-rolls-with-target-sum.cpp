class Solution {
public:
    
    int m =1e9+7;
    
    
    int findNumOfWays(int ind,int &n,int &k,int target,vector<vector<int>> &dp){
        if(ind==n+1 && target==0) return 1;
        if(ind == n+1) return 0;
        if(target<=0) return 0;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int noOfWays =0;
        for(int i=1;i<=k;i++){
            noOfWays=((noOfWays%m) +(findNumOfWays(ind+1,n,k,target-i,dp)%m)) % m;
        }
        
        return dp[ind][target]=noOfWays;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return findNumOfWays(1,n,k,target,dp);
    }
    
//     int dp[31][1001] = {};
// int numRollsToTarget(int d, int f, int target, int res = 0) {
//   if (d == 0 || target <= 0) return d == target;
//   if (dp[d][target]) return dp[d][target] - 1;
//   for (auto i = 1; i <= f; ++i)
//     res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
//   dp[d][target] = res + 1;
//   return res;
// }
};