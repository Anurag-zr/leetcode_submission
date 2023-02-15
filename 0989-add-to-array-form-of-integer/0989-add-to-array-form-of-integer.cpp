class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for(int i=num.size()-1;i>=0 || k>0;i--){
            ans.insert(ans.begin(),(i>=0? num[i]+k : k)%10);
            k = (i>=0? num[i]+k : k)/10;
        }
        
        return ans;
    }
};