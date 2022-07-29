class Solution {
public:
    
    int f(int ind,bool buy,vector<int> &prices,vector<vector<int>> &dp){
        if(ind == prices.size()){ return 0;}
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        
        int profit;
        //if buying allowed
        if(buy){
            //either buy
            int take  = -prices[ind] + f(ind+1,false,prices,dp);
            //or not buy
            int nottake = 0 + f(ind+1,true,prices,dp);
            profit = max(take,nottake);
        }
        //selling allowed
        else{
        //either sell
            int take = prices[ind] + f(ind+1,true,prices,dp);
            //or not sell
            int nottake = 0 +  f(ind+1,false,prices,dp);
            profit = max(take,nottake);
        }
        
        
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        //1 signify: at 0th index you can start buying stock
        bool buy = true;
        return f(0,buy,prices,dp);
    }
};