class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int var =n;
        if(n%2!=0) ans.push_back(0); // n is odd;
        
        while(ans.size()!=n){
            ans.push_back(var);
            ans.push_back(-var);
            var--;
        }
        
        return ans;
    }
};