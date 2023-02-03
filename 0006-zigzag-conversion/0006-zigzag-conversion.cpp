class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        int n = s.length();
        vector<vector<char>> arr(numRows,vector<char>(n,' '));
        int i=0,j=0;
        bool goingDown = true;
        for(int k=0;k<n;k++){
            char c = s[k];
            
            if(goingDown){
                if(i<numRows-1){
                    arr[i][j]=c;
                    i++;
                }
                else if(i==numRows-1){
                    goingDown = false;
                    arr[i][j]=c;
                    i--;
                    j++;
                }
            }
            else{
                if(i>0){
                arr[i][j]=c;
                i--;
                j++;
                }
                else if(i==0){
                    goingDown = true;
                    arr[i][j] = c;
                    i++;
                }
            }
            
        }
        
        string ans ="";
        
        for(auto it: arr){
            for(auto iit:it){
                if(iit==' ') continue;
                // cout<<iit<<" "; 
                ans+=iit;
            }
            // cout<<endl;
        }
        
        
        return ans;
    }
};