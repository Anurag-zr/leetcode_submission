class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //triangle property: sum of any 2 side must be greater than third side;
        
       for(int i= nums.size()-1;i>1;i--){ 
        if(nums[i-2]+nums[i-1]>nums[i]){
          return nums[i]+nums[i-1]+nums[i-2];
        }
       }
        
        return 0;
    }
};