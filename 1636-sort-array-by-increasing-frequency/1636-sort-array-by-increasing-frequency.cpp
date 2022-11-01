    // auto compare =[](pair<int,int> a, pair<int,int> b){
    //     if(a.first == b.first){
    //         return a.second < b.second; // higher value stay at top;
    //     }
    //     else return a.first> b.first; // smaller frequency stay at top;
    // };

    bool compare(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second < b.second; // higher value stay at top;
        }
        else return a.first> b.first; // smaller frequency stay at top;
    }

class Solution {
public:
        
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int> umap;
        
        for(auto i:nums){
            umap[i]++;
        }
        
        priority_queue< pair<int,int>,vector<pair<int,int>>, decltype(&compare)> pq(compare);
        
        for(auto it:umap){
            pq.push({it.second,it.first});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            
            while(p.first--){
                ans.push_back(p.second);
            }
        }
        
        return ans;
    }
};