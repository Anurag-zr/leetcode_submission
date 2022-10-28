class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        
        for(auto s:strs){
            umap[countSort(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it:umap){
            ans.push_back(it.second);
        }
        
        
        return ans;
    }
    
private: 
    string countSort(string ans){
        vector<int> freq(26,0);
        
        for(auto c:ans){
            freq[c-'a']++;
        }
        
        string t="";
        for(int i=0;i<26;i++){
           if(freq[i]!=0){
             
               while(freq[i] !=0){
                   t+=(i+'a');
                   freq[i]--;
               }
             
            }
        }
        
        return t;
    }

};