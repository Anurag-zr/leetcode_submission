class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        
        vector<pair<int,int>> zeros;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) zeros.push_back({i,j});
            }
        }
        
        for(auto it:zeros){
            int i=it.first;
            int j = it.second;
            
            //set row zero
            for(int k=0;k<n;k++){
                matrix[i][k]=0;
            }
            
            //set col zero
            for(int k=0;k<m;k++) matrix[k][j]=0;
        }
        

    }
};