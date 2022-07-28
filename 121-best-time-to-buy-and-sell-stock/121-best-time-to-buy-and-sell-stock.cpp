class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mini = prices[0];
        int profit =0;
        int currprofit;
        for(int i=1;i<n;i++){
            currprofit = prices[i]-mini;
            profit = max(profit,currprofit);
            mini = min(mini,prices[i]);
        }
        
        
        return profit;
    }
};