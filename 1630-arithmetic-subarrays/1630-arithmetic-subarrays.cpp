class Solution {
public:
    
    bool IsArithmeticSeq(vector<int> nums,int p,int q){
        sort(nums.begin()+p,nums.begin()+q+1);
        // for(auto e: nums) cout<<e<<" ";
        // cout<<endl;
        
        
        int d = nums[p+1]-nums[p];
        for(int ind =p;ind<q;ind++){
            if(nums[ind+1]-nums[ind]==d) continue;
            else return false;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        
        vector<bool> ans;
        
        for(int i=0;i<m;i++){
            int p = l[i];
            int q = r[i];
            
            ans.push_back(IsArithmeticSeq(nums,p,q));
        }
        
        return ans;
    }
};