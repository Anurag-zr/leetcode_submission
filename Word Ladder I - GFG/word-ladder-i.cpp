//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> listSet(wordList.begin(),wordList.end());
        if(listSet.find(targetWord)==listSet.end()) return 0;
        
        unordered_map<string,bool> vis;
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        vis[startWord]=true;
        
        while(!q.empty()){
            auto curpair = q.front();
            q.pop();
            string curWord =curpair.first;
            
            if(curWord==targetWord){
                return curpair.second;
            }
            
            
            for(int i=0;i<curWord.length();i++){
                char original = curWord[i];
                
                for(char ch='a';ch<='z';ch++){
                    curWord[i]=ch;
                    if(listSet.find(curWord)!=listSet.end() && !vis[curWord]){
                        vis[curWord]=true;
                        q.push({curWord,curpair.second+1});
                    }
                }
                
                curWord[i]=original;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends