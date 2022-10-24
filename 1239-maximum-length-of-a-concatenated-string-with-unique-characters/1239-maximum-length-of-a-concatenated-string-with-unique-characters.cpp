class Solution {
public:
    
    string maxLenHelper(int ind,vector<string> &arr,unordered_map<char,bool> &umap){
        if(ind==arr.size()) return "";
        
        string s = arr[ind];
        bool allUnique = true;
        
        vector<bool> check(26,false);
        
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()){
                allUnique = false;
                break;
            }
            else if(check[s[i]-'a']==true){
                allUnique = false;
                break;
            }
            else{
                check[s[i]-'a']=true;   
            }
        }
        
     
        
        string pick="";
        string notpick="";
        
        if(allUnique){ //pick s
            
            for(auto c:s){
                umap[c]=true;
            }
            
             pick = s+maxLenHelper(ind+1,arr,umap);
            
            for(auto c:s) umap.erase(c);
        
        }
        
        //not pick
        
        notpick=  maxLenHelper(ind+1,arr,umap);
        
        return  (pick.length()>notpick.length()?pick:notpick);
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map<char,bool> umap;
        string ans = maxLenHelper(0,arr,umap);
        return ans.length();
    }
};