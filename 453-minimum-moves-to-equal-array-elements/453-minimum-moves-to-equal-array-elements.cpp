class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0,num_min=INT_MAX;
        for(int a:nums){
            sum+=a;
            num_min=min(num_min,a);
        }
        return sum-(num_min*nums.size());
    }
};