class Solution {
public:
    
    void findCombinations(int ind,vector<int> &ds,int target,vector<int> &candidates,
                         vector<vector<int>> &ans){
        
        if(ind == candidates.size()){
            if(target == 0 ){
                ans.push_back(ds);
            }
            return;
        }
         
        //pick
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombinations(ind,ds,target-candidates[ind],candidates,ans);
            ds.pop_back();
        }
        
        //not pick
            findCombinations(ind+1,ds,target,candidates,ans);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,ds,target,candidates,ans);
        return ans;
    }
};