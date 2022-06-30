class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int median = nums[n/2];
        for(auto i:nums){
            steps+=abs(i-median);
        }
        
        return steps;
    }
};