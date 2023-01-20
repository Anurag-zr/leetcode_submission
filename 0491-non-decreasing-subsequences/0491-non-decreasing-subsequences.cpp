class Solution {
public:
    
    void helper(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> &nums){
        if(ds.size()>=2) ans.push_back(ds);
        
        
        set<int> hash;
        for(int i=ind;i<nums.size();i++){
            if((ds.empty() || nums[i]>=ds.back()) && hash.find(nums[i])==hash.end()){
                ds.push_back(nums[i]);
                helper(i+1,ds,ans,nums);
                ds.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> ds;
        
        helper(0,ds,ans,nums);
        
        return ans;
    }
};