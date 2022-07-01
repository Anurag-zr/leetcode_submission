class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      int sizebucket[1001]={0};
      int minUnitBox = INT_MAX;
      int maxUnitBox = INT_MIN;
       for(auto &boxType:boxTypes){
         maxUnitBox = max(maxUnitBox,boxType[1]);
         minUnitBox = min(minUnitBox,boxType[1]);
         sizebucket[boxType[1]]+=boxType[0];  
       } 
        
        // cout<< maxUnitBox<<minUnitBox;
        
        int noOfBoxes;
        int mxunits = 0;
        int currBatch;
        for(int i= maxUnitBox;i>=minUnitBox;i--){
            noOfBoxes = sizebucket[i];
            if(noOfBoxes == 0) continue;
            currBatch = min(noOfBoxes,truckSize);
            truckSize -= currBatch;
            mxunits += currBatch*i;
            if(truckSize == 0) break;
        }
        
        return mxunits;
    }
};