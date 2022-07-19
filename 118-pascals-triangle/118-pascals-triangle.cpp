class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> ds;
        for(int row = 0;row<numRows;row++){
            for(int col =0;col<=row;col++){
                
                if(col-1>=0 && row-1>=0 && col<row) 
                    ds.push_back(ans[row-1][col-1]+ans[row-1][col]);
                else ds.push_back(1);
            }
            
            ans.push_back(ds);
            ds.clear();
        }
        
        
        return ans;
    }
};