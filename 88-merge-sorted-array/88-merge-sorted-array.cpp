class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        vector<int> ans;
        int i=0; // ptr to num1
        int j=0; //ptr to num2
        // int k=0; //ptr to ans
        
        while(i<m && j<n){
            if(num1[i]<=num2[j]){
                ans.push_back(num1[i]);
                i++;
            }
            else{
                ans.push_back(num2[j]);
                j++;
            }
        }
        
        if(i==m && j<n){
            while(j<n){
                ans.push_back(num2[j]);
                j++;
            }
        }
        
        if(j==n && i<m){
            while(i<m){
                ans.push_back(num1[i]);
                i++;
            }
        }
        
        
        num1.clear();
        for(auto it:ans){
            num1.push_back(it);
        }
    }
};