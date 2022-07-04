class Solution {
public:
int lengthOfLongestSubstring(string s){
    int maxlength = 0;
    // int uniquechar = 0;
    unordered_map<char, int> umap;

    int i = 0;
    for (int j = 0; j < s.size();j++){
          umap[s[j]]++;
        if(umap.size() == j-i+1){
            maxlength = max(maxlength, j - i + 1);
        }
        else if(umap.size() < j-i+1){
            while(umap.size() < j-i+1){
                umap[s[i]]--;
                if(umap[s[i]]==0){
                    umap.erase(s[i]);
                }
                i++;
            }

            if(umap.size() == j-i+1){
                maxlength = max(maxlength, j - i + 1);
            }
        }
    }

    return maxlength;
}
};