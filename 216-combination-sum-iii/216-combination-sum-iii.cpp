class Solution {
public:
    
    void findCombinations(int ind,int length,int target,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        if(ind == nums.size()){
            if(target == 0 && length == 0){
                ans.push_back(ds);
            }
            
            return;
        }
        
        if(target>=nums[ind] && length>0){
            ds.push_back(nums[ind]);
            findCombinations(ind+1,length-1,target-nums[ind],nums,ds,ans);
            ds.pop_back();
        }
        
        findCombinations(ind+1,length,target,nums,ds,ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        vector<vector<int>> ans;
        findCombinations(0,k,n,nums,ds,ans);
        return ans;
    }
};