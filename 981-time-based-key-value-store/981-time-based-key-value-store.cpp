class TimeMap {
public:
    
    unordered_map<string,vector<int>> timeStamp;
    map<pair<string,int>,string> keyVal;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeStamp[key].push_back(timestamp);
        keyVal[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        if(timeStamp.find(key)==timeStamp.end()) return "";
        
        int floor = findFloor(timestamp,timeStamp[key]);
        
        // cout<<floor<<endl;
        
        return keyVal[{key,floor}];
    }
    
  private: 
     int findFloor(int key,vector<int> &times){
         int start = 0;
         int end = times.size()-1;
         
         int ans=-1;
         while(start<=end){
             int mid = start + (end-start)/2;
             
             if(key == times[mid]) return times[mid];
             else if(times[mid]<key){
                 ans = times[mid];
                 start = mid+1;
             }
             else{
                 end = mid-1;
             }
         }
         
         
         return ans;
     }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */