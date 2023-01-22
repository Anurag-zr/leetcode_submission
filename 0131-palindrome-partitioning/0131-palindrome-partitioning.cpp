class Solution {
public:
    
    bool isPalindrome(string s){
        int n = s.length();
        
        for(int i=0;i<=n/2;i++){
            if(s[i]==s[n-1-i]) continue;
            
            return false;
        }
        
        return true;
    }
    
  void helper(int ind,vector<string> &ds,string &s,vector<vector<string>> &ans){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=1;i<=s.length();i++){
            if(ind+i>s.length()) break;
            
            string subPart = s.substr(ind,i);

            
            if(isPalindrome(subPart)){
                ds.push_back(subPart);
                helper(ind+i,ds,s,ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        
        helper(0,ds,s,ans);
        
        return ans;
    }
};