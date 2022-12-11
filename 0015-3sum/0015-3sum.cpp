class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int first,sec,last,target;
        
        for(int i=0;i<nums.size()-2;i++){
            first =i;
            if(first>0 && nums[first]==nums[first-1]) continue;
            
            sec = first+1;
            last = n-1;
            
            target = -nums[first];
            
            while(sec<last){
                if(nums[sec]+nums[last]==target){
                    ans.insert({nums[first],nums[sec],nums[last]});
                    sec++;
                }
                else if(nums[sec]+nums[last]<target){
                    sec++;
                }
                else{
                    last--;
                }
            }
        }
        
        vector<vector<int>> res;
        for(auto it:ans){
            res.push_back(it);
        }
        
        return res;
    }
};