class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        return n > 0 && not (n & n - 1);
    }
    
    
    int constructNum(vector<int> &ds){
        int num=0;
        int rem=0;
        for(int i=0;i<ds.size();i++){
            rem=ds[i];
            num = 10*num +rem;
        }
        
        return num;
    }
    
    bool formCombination(int ind,vector<int> &digits,vector<int> &ds,vector<int> &freq, vector<vector<int>> &ans){
        if(ind == digits.size()){
            int num = constructNum(ds);
            return isPowerOfTwo(num);
        }
        
        
        for(int i=0;i<digits.size();i++){
           if(!freq[i]){
            if(ind ==0 && digits[i]==0) continue;
            ds.push_back(digits[i]);
               freq[i]=1;
            if(formCombination(ind+1,digits,ds,freq,ans)) return true;
               freq[i]=0;
            ds.pop_back();
           }
        }
        
        return false;
    }
    
    bool reorderedPowerOf2(int n) {
        if(isPowerOfTwo(n)) return true;
        vector<int> digits;
        
        int rem=0;
        while(n>0){
            rem=n%10;
            digits.push_back(rem);
            n=n/10;
        }
        
        vector<int> freq(digits.size(),0);
        vector<int> ds;
        vector<vector<int>> ans;
        
        return formCombination(0,digits,ds,freq,ans);
        
        // cout<<digits[digits.size()-1]<<endl;
        
        // for(auto it:ans){
        //     for(auto iit:it){
        //         cout<<iit<<" ";
        //     }
        //     cout<<endl;
        // }
        
    
    }
};