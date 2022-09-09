class Solution {
public:
    
   static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
         return a[0]>b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        
        int n = properties.size();
        
        int maxdefence = INT_MIN;
        int weakChar=0;
        
        for(int i=0;i<n;i++){
            if(properties[i][1]<maxdefence) weakChar++;
            maxdefence = max(maxdefence,properties[i][1]);
        }
        
        return weakChar;
    }
};