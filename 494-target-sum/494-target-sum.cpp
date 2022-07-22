class Solution {
public:
    
int f(int ind,int target,vector<int> &arr,map<pair<int,int>,int> &dp){
    if(ind==-1){
        if(target==0) return 1;
        else return 0;
    }
    
         if(dp.find(make_pair(ind, target)) != dp.end()){
            return dp[make_pair(ind, target)];
        }

    
    int neg = f(ind-1,target+arr[ind],arr,dp);
    int pos = f(ind-1,target-arr[ind],arr,dp);
    
    return dp[make_pair(ind,target)]=neg + pos;
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
      int n= nums.size();
      map<pair<int,int>,int> dp;
      return f(n-1,target,nums,dp);
    }
};