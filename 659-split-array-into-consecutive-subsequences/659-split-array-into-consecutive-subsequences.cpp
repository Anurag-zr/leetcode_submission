class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> availabilityMap,wantedMap;
        
        for(int ele:nums){
            availabilityMap[ele]++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(availabilityMap[nums[i]]==0) continue;
            else if(wantedMap[nums[i]]>0){
                availabilityMap[nums[i]]--;
                wantedMap[nums[i]]--;
                wantedMap[nums[i]+1]++;
            }
            else if(availabilityMap[nums[i]+1]>0 && availabilityMap[nums[i]+2]>0){
                availabilityMap[nums[i]]--;
                availabilityMap[nums[i]+1]--;
                availabilityMap[nums[i]+2]--;
                wantedMap[nums[i]+3]++;
            }
            else{
                return false;
            }
        }
        
        
        return true;
    }
};