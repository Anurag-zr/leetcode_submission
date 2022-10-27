class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int best =0;
        int n = img1.size();
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                best = max(best,overlapOnes(img1,img2,i,j));
            }
        }
        
        return best;
    }
    
private: 
    int overlapOnes(vector<vector<int>> &A,vector<vector<int>> &B,int iOff,int jOff){
        int n=A.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+iOff<0 || i+iOff>=n || j+jOff<0 || j+jOff>=n) continue;
                
                if(A[i][j]==1 && B[i+iOff][j+jOff]==1) count++;
            }
        }
        
        
        return count;
    }
};