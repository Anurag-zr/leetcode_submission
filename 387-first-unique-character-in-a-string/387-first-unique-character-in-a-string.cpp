class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> umap;
        
        for(int i=0;i<s.length();i++){
            umap[s[i]].first++;
            umap[s[i]].second = i;
        }
        
        int ind = INT_MAX;
        
        for(auto &[c,p]:umap){
            if(p.first == 1){
                ind = min(ind,p.second);
            }
        }
        
        return ind==INT_MAX?-1:ind;
    }
};