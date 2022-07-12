class Solution {
public:
    int mySqrt(int x) {
        long long start =0;
        long long end = x/2+1;
        long long ans;
        
        while(start<=end){
            long long mid = start + (end-start)/2;
            
            if(mid*mid>x){
                end = mid-1;
            }
            else if(mid*mid<x){
                ans = mid;
                start = mid+1;
            }
            else{
                return mid;
            }
        }
        
        return ans;
    }
};