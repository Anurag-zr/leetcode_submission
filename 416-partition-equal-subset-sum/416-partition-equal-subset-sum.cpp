class Solution {
public:
    
    bool subsetSumEqualTarget(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        
        if(target==0) return true;
        if(ind ==0) return (nums[0]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nottake = subsetSumEqualTarget(ind-1,target,nums,dp);
        bool take = false;
        if(nums[ind]<=target){
            take = subsetSumEqualTarget(ind-1,target-nums[ind],nums,dp);
        }
        
        return dp[ind][target] =(nottake | take);
    }
    
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totalSum=0;
        for(auto i: nums){
            totalSum+=i;
        }
        
        if(totalSum%2==0){
            vector<vector<int>> dp(n,vector<int> (totalSum/2+1,-1));
        return subsetSumEqualTarget(n-1,totalSum/2,nums,dp);
        }
        else
            return false;
    }
};