class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i=n-1;
        int j=0;
        
        while(i>0){
             int row =i;
             int col = j;
            
            while(row<n && col<m){
                // cout<<row<<" "<<col<<endl;
                if(matrix[i][j]==matrix[row][col]){
                    row++;
                    col++;
                }
                else{
                    return false;
                }
            }
            
            i--;
        }
        
        if(i==0){
             while(j<m){
                 int row = i;
                 int col =j;
                 
                 while(row<n && col<m){
                     // cout<<endl;
                     // cout<<row<<" "<<col<<endl;
                     if(matrix[i][j]==matrix[row][col]){
                         row++;
                         col++;
                     }
                     else{
                         return false;
                     }
                 }
                 
                 j++;
             }
        }
        
        
        
        return true;
    }
};