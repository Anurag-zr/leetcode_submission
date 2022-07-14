class Solution {
public:
    int rob(vector<int>& nums) {
      //space optimization technique 
        //build logic using recursion |dp memoization |tabulation then this...
        int n= nums.size();
        int prev1=nums[0];
        int prev2=0;
        int curi;
        
        int pick,notpick;
        
        for(int i=1;i<n;i++){
            //take
            pick = nums[i]+prev2;
            //not take
            notpick = 0+prev1;
            
            curi = max(pick,notpick);
            prev2 = prev1;
            prev1=curi;
        }
        
        return prev1;
    }
};