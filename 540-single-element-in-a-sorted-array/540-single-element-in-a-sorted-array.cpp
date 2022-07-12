class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        
        int start=0;
        int end =n-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(mid>0 && mid<n-1){
                
                if(nums[mid]==nums[mid-1]){
                    if((mid-1)%2==0){
                        start=mid+1;
                    }
                    else end=mid-2;
                }
                else if(nums[mid]==nums[mid+1]){
                    if(mid%2==0){
                        start=mid+2;
                    }else{
                        end=mid-1;
                    }
                }
                else{
                    return nums[mid];
                }
            }
            
            
            if(mid==0){
                if(nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
            }
            if(mid==n-1){
                if(nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }
            }
        }
        
        
        return -1;
    }
};