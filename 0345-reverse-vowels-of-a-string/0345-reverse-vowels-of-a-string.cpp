class Solution {
public:
    string reverseVowels(string s) {
        // cout<<s<<endl;
        int  i,j;
        i=0;
        j= s.length()-1;
        
        // cout<<j<<endl;
        
        unordered_map<char,int> umap;
        umap['a']++;
        umap['e']++;
        umap['i']++;
        umap['o']++;
        umap['u']++;
        umap['A']++;
        umap['E']++;
        umap['I']++;
        umap['O']++;
        umap['U']++;
        
        while(i<j){
            
            while(i<j && umap.find(s[i])==umap.end()){ 
                // cout<<s[i]<<endl;
                i++;
            }
            
            while(i<j && umap.find(s[j])==umap.end()){
              // cout<<s[j]<<endl;
                j--;
            } 
            
            if(i<j){
                // cout<<s[i]<<" "<<s[j]<<endl; 
                char temp = s[i];
                s[i]=s[j];
                s[j]=temp;
                
                 i++;
                j--;
            }
            

        }
        
        
        return s;
    }
};