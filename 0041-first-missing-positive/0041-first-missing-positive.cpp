class Solution {
public:
    
    
    int firstMissingPositive(vector<int>& nums) {
        
        //bruteforce
        sort(nums.begin(),nums.end());
        int ans =1;
        
        for(auto i:nums){
            if(i<1) continue;
            if(i==ans) ans++;
            if(i>ans) break;
        }
        
        return ans;
    }
};