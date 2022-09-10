class Solution {
public:
    
    int helper(int ind,bool canBuy,int k,vector<int> &prices,        vector<vector<vector<int>>> &dp){
        
        if(ind == prices.size()){
            return 0;
        }
        
        if(k<=0 && canBuy==true) return 0;
        
        if(dp[ind][canBuy][k]!=-1) return dp[ind][canBuy][k];
        
        
        int profit;
        
        if(canBuy){
            int buy =-prices[ind]+helper(ind+1,false,k-1,prices,dp);
            
            int notBuy =0+ helper(ind+1,true,k,prices,dp);
            
            profit =max(buy,notBuy);
        }
        
        else{
            
            int sell = prices[ind]+helper(ind+1,true,k,prices,dp);

            int notSell =0+ helper(ind+1,false,k,prices,dp);
            
            profit =max(sell,notSell);
        }
        
        
        return dp[ind][canBuy][k]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        bool canBuy =true; //intially we can buy
        int boughtItemInd=-1; //store index of bought item
        
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (k+1,-1)));
        int profit = helper(0,canBuy,k,prices,dp);
        
        return profit;
    }
};