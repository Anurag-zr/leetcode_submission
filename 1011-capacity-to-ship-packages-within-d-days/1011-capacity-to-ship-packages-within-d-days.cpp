class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        for(auto ele: weights) sum+=ele;
        
        int minCap = ceil(sum/days);
        
        for(int cap = minCap;cap<=sum;cap++){
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
            
            if(rDays<=days) return cap;
        }
        
        
        
        return 0;
    }
};