class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n= s.length();
        int m = p.length();
        
        if(m>n) return {};

        unordered_map< char,int> map1;
        unordered_map<char,int> map2;
        
        for(auto c: p) map1[c]++;
        
        vector<int> ans;
        int i=0;
        for(int j=0;j<s.length();j++){
            
            if(j-i+1<=m){
                if(map1.find(s[j])==map1.end()){
                    map2.clear();
                    i=j+1;
                    continue;
                }
                
                map2[s[j]]++;
            }
            
            if(j-i+1==m){
                if(map1==map2){
                    ans.push_back(i);
                }
                
                    map2[s[i]]--;
                    if(map2[s[i]]==0) map2.erase(s[i]);
                    i++;
                
            }

        }
        
        return ans;
    }
};