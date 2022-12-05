class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length() != word2.length()) return false;
        
       unordered_map<char,int> fmap1;
        unordered_map<char,int> fmap2;
        
        for(auto c:word1) fmap1[c]++;
        for(auto c:word2) fmap2[c]++;
        
        vector<char> c_in_word1;
        vector<int> f_in_word1;
        vector<char> c_in_word2;
        vector<int> f_in_word2;
        
        for(auto it:fmap1){
          c_in_word1.push_back(it.first);
          f_in_word1.push_back(it.second);
        }
        
        for(auto it:fmap2){
            c_in_word2.push_back(it.first);
            f_in_word2.push_back(it.second);
        }
        
        sort(c_in_word1.begin(),c_in_word1.end());
        sort(c_in_word2.begin(),c_in_word2.end());
        
        sort(f_in_word1.begin(),f_in_word1.end());
        sort(f_in_word2.begin(),f_in_word2.end());
        
        if(c_in_word1 == c_in_word2  && f_in_word1 == f_in_word2) return true;
        
        return false;
    }
};