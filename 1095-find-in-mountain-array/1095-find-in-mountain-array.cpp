/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &arr) {
        int start =0;
        int end =arr.length()-1;
        
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr.get(mid+1)>arr.get(mid)){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        
        return start;//or end
    }
               
               
    int bs(MountainArray &arr,int start,int end,int target,int asc){
        
        while(start<=end){
            int mid = start + (end - start)/2;
            
            if(arr.get(mid)<target){
                if(asc) start=mid+1;
                else end = mid-1;
            }
            else if(arr.get(mid)>target){
                if(asc) end = mid -1;
                else  start =mid+1;
            }
            else{
                return mid;
            }
        }
        
        return -1;
    }
               
               
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakInd = peakIndexInMountainArray(mountainArr);
        int lsearch = bs(mountainArr,0,peakInd,target,true);
        if(lsearch!=-1) return lsearch;
        return bs(mountainArr,peakInd+1,mountainArr.length()-1,target,false);
    }
};