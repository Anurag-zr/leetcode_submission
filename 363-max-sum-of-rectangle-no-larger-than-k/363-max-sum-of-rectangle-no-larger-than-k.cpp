class Solution {
public:
    
    void makePrefixSumArr(vector<vector<int>> &matrix,vector<vector<int>> &prefix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                prefix[i][j]+=matrix[i][j];
                if(i-1>=0) prefix[i][j]+=prefix[i-1][j];
                if(j-1>=0) prefix[i][j]+=prefix[i][j-1];
                if(i-1>=0 && j-1>=0) prefix[i][j]-=prefix[i-1][j-1];
            }
        }
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> prefix(matrix.size(),vector<int>(matrix[0].size(),0));
        makePrefixSumArr(matrix,prefix);
                                  
        int maxi = INT_MIN;
        int row = matrix.size();
        int col = matrix[0].size();
                                  
        int sum;
                                  
        for(int up=0;up<row;up++){
            for(int down = up;down<row;down++){
                for(int left =0;left<col;left++){
                    for(int right = left;right<col;right++){
                        sum=0;
                        sum+=prefix[down][right];
                        if(left-1>=0) sum-=prefix[down][left-1];
                        if(up-1>=0) sum-=prefix[up-1][right];
                        if(up-1>=0 && left-1>=0) sum+=prefix[up-1][left-1];
                        
                        if(sum==k){
                            return sum;
                        }
                        else if(sum<k)
                        maxi = max(sum,maxi);
                    }
                }
            }
        }
                                  
        return maxi;
    }
};