class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0+ max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    int lenSCS = n+m - dp[n][m];  
    string ans (lenSCS,'$');
    int index = lenSCS-1;

        int i=n;
        int j = m;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans[index] = a[i-1];
                i--;
                j--;
                index--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    ans[index]=b[j-1];
                    index--;
                    j--;
                }
                else{
                    ans[index] = a[i-1];
                    index--;
                    i--;
                }
            }
        }

        if(i==0 && j>0){
            while(j>0){
                ans[index] = b[j-1];
                index--;
                j--;
            }
        }

        if(j==0 && i>0){
            while(i>0){
                ans[index]= a[i-1];
                index--;
                i--;
            }
        }    
    
    return ans;
    }
};