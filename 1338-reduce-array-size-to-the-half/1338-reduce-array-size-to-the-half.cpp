class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> freq;
        for(auto ele:arr){
            freq[ele]++;
        }
    
        vector<int> counting(n+1);
        for(auto &[_,cnt]:freq) counting[cnt]++; //{0,1,1,0,1,0,0......}
        
        
        int freqcy =n;
        int ans=0;
        int setSize =n;
        while(setSize>n/2){
            
            if(counting[freqcy]==0) freqcy--;
            else{
                setSize-=freqcy;
                ans++;
                counting[freqcy]--;
            }
        }
        
       return ans;
    }
};