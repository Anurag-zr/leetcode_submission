class Solution {
public:
    
   static bool compare(pair<int,char> a,pair<int,char> b){
        if(a.first == b.first) return  a.second -'a' < b.second -'a'; //high ascii val at top
            
            return a.first<b.first; //high freq is at top
    }
    
    int minDeletions(string s) {
        unordered_map<char,int> umap;
        
        for(auto c: s) umap[c]++;
        
        priority_queue<pair<int,char>,vector<pair<int,char>>,decltype(&compare)> pq(compare);
        
        for(auto it:umap){
            pq.push({it.second,it.first});
        }
        
        int minDel =0;
        int prevFreq = INT_MAX;
        while(!pq.empty()){
            int curFreq = pq.top().first;
            // char curC = pq.top().second;
            pq.pop();
            
            // cout<<curC<<" "<<curFreq<<endl;
            
            if(prevFreq<=curFreq){
                prevFreq = max(0, prevFreq-1);
                minDel+= curFreq-prevFreq;
            }
            else{
                prevFreq = curFreq;
            }
            
        }
        
        return minDel;
    }
};