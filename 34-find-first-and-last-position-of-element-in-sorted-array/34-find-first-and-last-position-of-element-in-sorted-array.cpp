class Solution {
public:
    
    int search(vector<int> &nums,int target,bool findFirst){
        int n= nums.size();
        int start=0;
        int end =n-1;
        int ans=-1;
        
        while(start<=end){
            int mid = start + (end - start)/2;
            if(target<nums[mid]){
                end = mid -1;
            }
            else if(target>nums[mid]){
                start=mid +1;
            }
            else{
                ans=mid;
                if(findFirst) end=mid-1;
                else start = mid+1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==0){
            return {-1,-1};
        }
        
        bool findFirst;
        int firstOccurence = search(nums,target,findFirst=true);
        int lastOccurence  = search(nums,target,findFirst=false);
        
        return {firstOccurence,lastOccurence};
    }
};