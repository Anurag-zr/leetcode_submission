class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1,0);
        int found =-1;
        for(int i=0;i<n;i++){
            if(++check[nums[i]]==2) found = nums[i]; 
        }
        
        // cout<<found<<endl;
        
        vector<int> ans ={found};
        for(int i=1;i<check.size();i++){
            if(check[i]==0) ans.push_back(i);
        }
        
        return ans;
    }
};