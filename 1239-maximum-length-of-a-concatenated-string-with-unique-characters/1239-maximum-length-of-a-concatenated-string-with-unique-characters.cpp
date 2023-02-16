class Solution {
public:
    
    int dfs(int ind,vector<string> &arr,string str){
        if(!isUnique(str)) return 0;
        
        int maxi =str.length();
        
        for(int i=ind;i<arr.size();i++){
            maxi = max(maxi,dfs(i+1,arr,str+arr[i]));
        }
        
        return maxi;
    }
    
    bool isUnique(string s){
        unordered_set<char> st(s.begin(),s.end());
        
        if(st.size()==s.length()) return true;
        return false;
    }
    
    int maxLength(vector<string>& arr) {
        int maxi = dfs(0,arr,"");
        return maxi;
    }
};