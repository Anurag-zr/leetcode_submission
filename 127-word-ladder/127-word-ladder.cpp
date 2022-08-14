class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        
        unordered_map<string,bool> visited;
        
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;
        int ladder =1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string word = q.front();
                q.pop();
                
                if(word == endWord) return ladder;
                
                // dict.erase(word);
                
                for(int j=0;j<word.size();j++){
                    char c = word[j];
                    for(int k='a';k<='z';k++){
                        word[j]= (char) k;
                        if(dict.find(word) != dict.end() && !visited[word]){
                            q.push(word);
                            visited[word]=true;
                        }
                    }
                    
                    word[j] = c;
                }
            }
            
            ladder++;
        }
        
        return 0;
    }
};