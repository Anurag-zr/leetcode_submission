my try get almost correct result
​
class Solution {
public:
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
//         int prevGrowTime = 0;
//         int n = plantTime.size();
//         int days =0;
//         for(int i=0;i<n;i++){
//             int curPlantTime = plantTime[i];
//             int curGrowTime = growTime[i];
//             days-= prevGrowTime;
//             days+= curPlantTime +curGrowTime;
//             prevGrowTime = curGrowTime;
//         }
//         return days;
int prefixSum=0;
for(auto i:plantTime) prefixSum+=i;
return prefixSum+*min_element(growTime.begin(),growTime.end());
}
};