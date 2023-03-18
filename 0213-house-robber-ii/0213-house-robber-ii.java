class Solution {
    
    public int helper(int startInd,int endInd,int[] nums,int[] dp){
        
        if(startInd == endInd) return nums[endInd];
        if(endInd<startInd) return 0;
        if(dp[endInd]!=-1) return dp[endInd];
        
        //pick
        int pick = nums[endInd] + helper(startInd,endInd-2,nums,dp);
        
        //not pick
        int notPick =0+ helper(startInd,endInd-1,nums,dp);
        
        return dp[endInd] = Math.max(pick,notPick);
    }
    
    public int rob(int[] nums) {
        int n = nums.length;
        
        if(n==1) return nums[0];
        
        int[]  dp = new int[n];
        Arrays.fill(dp,-1);
        
        // leave last element
        int ans1 = helper(0,n-2,nums,dp);
        // System.out.println(ans1);
        
        // leave first element
        Arrays.fill(dp,-1);
        int ans2 = helper(1,n-1,nums,dp);
        // System.out.println(ans2);
        
        return Math.max(ans1,ans2);
    }
}