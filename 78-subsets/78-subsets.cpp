class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
    
        for(int i=0;i< pow(2,n);i++){
            for(int ind = 0; ind<n;ind++){
                if(i & (1<<ind))  ds.push_back(nums[ind]);
            }
            ans.push_back(ds);
            ds.clear();
        }
        
        
        return ans;
    }
};