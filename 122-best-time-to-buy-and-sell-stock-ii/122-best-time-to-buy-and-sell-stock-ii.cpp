class Solution {
public:
    
//     int f(int ind,bool buy,vector<int> &prices,vector<vector<int>> &dp){
//         if(ind == prices.size()){ return 0;}
        
//         if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        
//         int profit;
//         //if buying allowed
//         if(buy){
//             //either buy
//             int take  = -prices[ind] + f(ind+1,false,prices,dp);
//             //or not buy
//             int nottake = 0 + f(ind+1,true,prices,dp);
//             profit = max(take,nottake);
//         }
//         //selling allowed
//         else{
//         //either sell
//             int take = prices[ind] + f(ind+1,true,prices,dp);
//             //or not sell
//             int nottake = 0 +  f(ind+1,false,prices,dp);
//             profit = max(take,nottake);
//         }
        
        
//         return dp[ind][buy] = profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         // int n = prices.size();
//         // vector<vector<int>> dp(n,vector<int> (2,-1));
//         // //1 signify: at 0th index you can start buying stock
//         // bool buy = true;
//         // return f(0,buy,prices,dp);
        
//         int n = prices.size();

//             vector<int> prev(2, 0);
//             vector<int> cur(2, 0);

//             for (int ind = n - 1; ind >= 0;ind--){
//                 for (int buy = 0; buy <= 1;buy++){
//                     int profit;
//                     if(buy){
//                         //buy
//                         int  buy = -prices[ind] + prev[0];
//                         //not buy
//                         int notbuy = 0 + prev[1];

//                         profit = max(buy,notbuy);
//                     }
//                     else{
//                         //sell
//                         int  sell = prices[ind] + prev[1];
//                         //not sell
//                         int notsell = 0+ prev[0];

//                         profit = max(sell,notsell);
//                     }

//                      cur[buy] = profit;

//                 }

//                 prev = cur;
//             }

//             return prev[1];
        
//      }
    
    
    int maxProfit(vector<int> &prices){
        int n = prices.size();
        int aheadNotBuy = 0;
        int aheadBuy = 0;
        int curNotBuy, curBuy;

        for (int ind = n - 1; ind >= 0;ind--){
            curNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

            aheadNotBuy = curNotBuy;
            aheadBuy = curBuy;
        }

        return aheadBuy;
    }
};