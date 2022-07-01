class Solution {
public:
    
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(),boxTypes.end(),comp);
        int n= boxTypes.size();
        int i=0;
        int mxunit =0;
        while(truckSize != 0 && i<n){
            if(truckSize>=boxTypes[i][0]){
                mxunit+= (boxTypes[i][0]*boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else if(truckSize< boxTypes[i][0]){
                mxunit+= truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            
            i++;
        }
            
            return mxunit;
    }
};