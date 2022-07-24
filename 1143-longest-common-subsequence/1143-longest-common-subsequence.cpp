class Solution {
public:
    
    int f(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &dp){
        
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        //if text1[ind1]  == text2[ind2]  matches
        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2] = 1 + f(ind1-1,ind2-1,text1,text2,dp);
        else
            return dp[ind1][ind2] = 0 + max(f(ind1-1,ind2,text1,text2,dp),
                                            f(ind1,ind2-1,text1,text2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m= text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        //memoization solution
        return f(n-1,m-1,text1,text2,dp);
        
        //tabulation
        
        
    }
};