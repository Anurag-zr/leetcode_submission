class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int ceil=-1;
        int start = 0;
        int end = arr.size()-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(arr[mid]==target) return mid;
            else if(target<arr[mid]){
                ceil = mid;
                end = mid-1;
            }
            else{ //target>arr[mid]
                start = mid+1;
            }
        }
        
        
        if(ceil ==-1) return arr.size();
        
        return ceil;
    }
};