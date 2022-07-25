class Solution {
public:
//  memoized solution    
//     int lcs(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    
//         if(i<0 || j<0) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]==t[j]) return dp[i][j] = 1 + lcs(i-1,j-1,s,t,dp);
//         return dp[i][j] = 0+max(lcs(i,j-1,s,t,dp),lcs(i-1,j,s,t,dp));
//     }
    
    int longestPalindromeSubseq(string s) {
         string t = s;
         reverse(t.begin(),t.end());
         int n= s.length();
          vector<vector<int>> dp(n+1,vector<int> (n+1,0));
         
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                 if(s[i-1]==t[j-1])
                     dp[i][j] = 1 + dp[i-1][j-1];
                 else
                 dp[i][j] = 0+max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        
        return dp[n][n];
    }
};