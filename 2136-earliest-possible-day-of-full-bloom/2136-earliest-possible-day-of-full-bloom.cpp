class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> times(n);
        
        for(int i=0;i<n;i++){
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        
        sort(times.begin(),times.end());
        
        int timeToBlossom =0;
        int curTime =0;
        
        for(auto it: times){
            timeToBlossom  = max(timeToBlossom,curTime+it.second - it.first);
            curTime+=it.second;
        }
        
        return timeToBlossom;
    }
};