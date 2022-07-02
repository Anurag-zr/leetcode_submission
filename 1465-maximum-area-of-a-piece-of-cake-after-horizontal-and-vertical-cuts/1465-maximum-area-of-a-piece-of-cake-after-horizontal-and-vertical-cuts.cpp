class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxHeight =INT_MIN;
        maxHeight = max(horizontalCuts[0]-0,
                        h- horizontalCuts[horizontalCuts.size() -1]);
        
        for(int i=1;i<horizontalCuts.size();i++){
            int height = horizontalCuts[i] - horizontalCuts[i-1];
            maxHeight = max(height,maxHeight);
        }
        
        int maxWidth = INT_MIN;
        maxWidth = max(verticalCuts[0]-0,w-verticalCuts[verticalCuts.size()-1]);
        
        for(int i=1;i<verticalCuts.size();i++){
            int width = verticalCuts[i] - verticalCuts[i-1];
            maxWidth = max(width,maxWidth);
        }
        
        long long ans = 1LL * maxHeight * maxWidth;
        
        return (int)(ans % 1000000007);
     }
};