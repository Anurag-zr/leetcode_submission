class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.length();
        int m = s2.length();
        
        if(n>m) return false;
        unordered_map< char,int> map1;
        unordered_map<char,int> map2;
        
        for(auto c: s1) map1[c]++;
        
        int i=0;
        for(int j=0;j<s2.length();j++){
            
            if(j-i+1<=n){
                if(map1.find(s2[j])==map1.end()){
                    map2.clear();
                    i=j+1;
                    continue;
                }
                
                map2[s2[j]]++;
            }
            
            if(j-i+1==n){
                if(map1==map2) return true;
                else{
                    map2[s2[i]]--;
                    if(map2[s2[i]]==0) map2.erase(s2[i]);
                    i++;
                }
            }

        }
        
        return false;
    }
};