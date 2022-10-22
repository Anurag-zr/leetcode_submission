class Solution {
public:
    string minWindow(string s, string t) {
       
        int n = s.length();
        int m = t.length();
        
        if(m>n) return "";
        
        unordered_map<char,int> umap;
        
        for(auto it:t){
            umap[it]++;
        }
        
        int count = umap.size();
        string ans="";
        
        int i=0;
        for(int j=0;j<n;j++){
            if(umap.find(s[j])!=umap.end()){//char exist
                umap[s[j]]--;
                if(umap[s[j]]==0) count--;
            }
            
            
            
                    
        if(count==0){
            
            if(ans.length()==0 || ans.length()>j-i+1) 
                ans = s.substr(i,j-i+1);
            
            while(count==0){
                if(umap.find(s[i])!=umap.end()){
                    umap[s[i]]++;
                    if(umap[s[i]]>0) count++;
                }    
                
                i++;
            }
            
            i--;
            umap[s[i]]--;
            count--;
            
            if(count==0){
                if(ans.length()>j-i+1) 
                    ans = s.substr(i,j-i+1);
            }
        }
            
            
    }

        
        return ans;
    }
};