class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int  cx1= max(ax1,bx1);  // common area first x coordinate
        int cy1 = max(ay1,by1);  // common area first y coordinate
        
        int cx2 = min (ax2,bx2);  // common area second x coordinate
        int cy2 = min(ay2,by2);  // common area second  y coordinate
        
        int commonArea =0;
        
        if(cx1<=cx2 && cy1<=cy2) commonArea = (cx2-cx1) * (cy2-cy1);
        
        int areaA = (ax2-ax1) * (ay2-ay1);
        int areaB = (bx2-bx1) * (by2-by1);
        
        
        
        return (areaB + areaA - commonArea);
    }
};