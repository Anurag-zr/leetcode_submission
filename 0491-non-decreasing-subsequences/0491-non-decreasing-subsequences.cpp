class Solution {
public:
    
    void helper(int ind,int prev,vector<int> &ds,set<vector<int>> &ans,vector<int> &nums){
        
        if(ind == nums.size()){
            if(ds.size()>=2) ans.insert(ds);
            return;
        }
        
        //pick
        if(nums[ind]>=prev){
            ds.push_back(nums[ind]);
            helper(ind+1,nums[ind],ds,ans,nums);
            ds.pop_back();
        }
        
        //not pick
        
        helper(ind+1,prev,ds,ans,nums);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       set<vector<int>> possibleSubseq;
        vector<int> ds;
        helper(0,-101,ds,possibleSubseq,nums);
        
        vector<vector<int>> ans;
        
        for(auto it: possibleSubseq){
            ans.push_back(it);
        }
        
      
        return ans;
    }
};