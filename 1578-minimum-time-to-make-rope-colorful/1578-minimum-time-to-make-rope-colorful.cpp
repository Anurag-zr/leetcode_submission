class Solution {
public:
    
//     int findMinCost(int prev,int cur,string &colors,vector<int> &neededTime,vector<vector<int>> &dp){
//         if(cur>=colors.length()) return 0;
        
//         if(dp[prev][cur]!=-1) return dp[prev][cur];
        
//         int minCost =0;
        
//         if(colors[prev]==colors[cur]){
//             int take = neededTime[prev] + findMinCost(prev+1,cur+1,colors,neededTime,dp);
//             int nottake = neededTime[cur] + findMinCost(prev,cur+1,colors,neededTime,dp);
            
//             cout<<take <<" "<<nottake<<" "<<prev<<" "<<cur<<endl;
            
//             minCost = min(take,nottake);
//         }
//         else{
//             minCost = 0+findMinCost(prev=cur,cur+1,colors,neededTime,dp);
//             cout<<minCost<<endl;
//         }
        
//         return dp[prev][cur]=minCost;
//     }
    
    
//     int minCost(string colors, vector<int>& neededTime) {
//      if(colors.length()==0 || colors.length()==1) return 0;
        
//         vector<vector<int>> dp(colors.length(),vector<int> (colors.length(),-1));
        
//         return findMinCost(0,1,colors,neededTime,dp);
//     }
    
    int minCost(string colors,vector<int> &neededTime){
        if(colors.length()==0 || colors.length()==1) return 0;
        
        int prev =0;
        int cur=1;
        
        int minTime =0;
        while(prev<colors.length() && cur<colors.length() ){
            if(colors[prev]==colors[cur]){
                if(neededTime[prev]<=neededTime[cur]){
                    minTime+=neededTime[prev];
                    prev=cur;
                    cur=cur+1;
                }
                else{
                    minTime+=neededTime[cur];
                    cur=cur+1;
                }
            }
            else{
                prev=cur;
                cur=cur+1;
            }
             
           
        }
        
        return minTime;
    }
};