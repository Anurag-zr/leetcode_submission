class Solution {
    
//     public int lcs(int ptr1,int ptr2,String text1,String text2,int[][] dp,String ans){
//         if(ptr1 == text1.length()) return 0;
//         if(ptr2 == text2.length()) return 0;
//         if(dp[ptr1][ptr2]!=-1) return dp[ptr1][ptr2];
        
//         if(text1.charAt(ptr1)==text2.charAt(ptr2)){
//             ans+=text1.charAt(ptr1);
//             return dp[ptr1][ptr2]=1+lcs(ptr1+1,ptr2+1,text1,text2,dp,ans);
//         }
//         else{
               
//             return  dp[ptr1][ptr2]=Math.max(lcs(ptr1+1,ptr2,text1,text2,dp,ans),
//                                            lcs(ptr1,ptr2+1,text1,text2,dp,ans));
            
//         }
//     }
    
//     public int longestCommonSubsequence(String text1, String text2) {
//         int n = text1.length();
//         int m = text2.length();
//         int dp[][] = new int[n][m];
//         for(int i=0;i<n;i++){
//             Arrays.fill(dp[i],-1);
//         }
        
//         String ans="";
//         return lcs(0,0,text1,text2,dp,ans);
//     }
    
    public int longestCommonSubsequence(String text1,String text2){
        int n = text1.length();
        int m = text2.length();
        
        int dp[][] = new int[n+1][m+1];// shifting of indexes
        for(int[] row: dp){
            Arrays.fill(row,-1);
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        
        
        for(int r=1;r<=n;r++){
            for(int c=1;c<=m;c++){
                if(text1.charAt(r-1)==text2.charAt(c-1)){
                    dp[r][c]= 1+ dp[r-1][c-1];
                }
                else{
                    dp[r][c]=0+ Math.max(dp[r-1][c],dp[r][c-1]);
                }
            }
        }
        
        
        return dp[n][m];
    }
}