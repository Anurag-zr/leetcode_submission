class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> umap;
        
        int ind =0;
        for(auto c: order){
            if(umap.find(c)==umap.end()){
                umap[c]=ind;
                ind++;
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            string a = words[i];
            string b = words[i+1];
            
            for(int j=0;j<a.length();j++){
                if(j>=b.length()) return false;
                if(a[j]!=b[j]){
                   if(umap[a[j]]>umap[b[j]]) return false;
                    
                    break;
                }
            }
        }
        
        return true;
    }
};