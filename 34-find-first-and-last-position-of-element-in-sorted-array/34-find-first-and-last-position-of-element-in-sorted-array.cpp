class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==0){
            return {-1,-1};
        }
        
        if(n==1 && nums[0]==target) return {0,0};
        
        int firstOccurence = -1;
        int start =0;
        int end = n-1;
        
        while(start<=end){
            int mid= start + (end-start)/2;
            
            if(nums[mid]==target){
                firstOccurence = mid;
                end=mid-1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        
        int lastOccurence =-1;
        start =0;
        end=n-1;
        
        while(start<=end){
            int mid= start + (end-start)/2;
            
            if(nums[mid]==target){
                lastOccurence = mid;
                start=mid+1;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        
        return {firstOccurence,lastOccurence};
    }
};