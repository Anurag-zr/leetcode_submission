class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength =0;
        unordered_map<char,int> umap;
        
        int i=0;
        for(int j=0;j<s.length();j++){
            if(umap.find(s[j])==umap.end()){ //char don't exist: unique char
                umap[s[j]]=1;
                maxlength = max(maxlength,j-i+1);
            }
            else{ //repeating character
                while(umap.find(s[j])!=umap.end()){
                    umap.erase(s[i]);
                    i++;
                }
                
                umap[s[j]]=1;
                maxlength = max(maxlength,j-i+1);
            }
        }
        
        return maxlength;
    }
};