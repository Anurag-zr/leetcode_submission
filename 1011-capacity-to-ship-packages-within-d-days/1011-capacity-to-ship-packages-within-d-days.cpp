class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        int left=0;
        for(auto ele: weights){
            left = max(left,ele);
            sum+=ele;
        }
        
        int right = sum;
        
        
        while(left<right){
            
            int mid = left + (right - left)/2;
            int cap = mid;
            int curW=0;
            int rDays=1;
            
            for(auto ele: weights){
                if(ele>cap){
                    rDays = 1e9;
                    break;
                }
                
                if(curW+ele<=cap){
                    curW+=ele;
                }
                else{
                    curW=ele;
                    rDays++;
                }
            }
            
            // cout<<cap<<" "<<rDays<<endl;
            
            if(rDays>days) left=mid+1;
            else right = mid;
        }
        
        
        
        return left;
    }
};