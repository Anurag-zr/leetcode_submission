class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count =0;
        int n=nums.size();
        
        int i=0;
        while(i<n){
            if(nums[i]==val){
                count++;
                int j=i;
                while(j+1<n){
                    nums[j]=nums[j+1];
                    j++;
                }
                n--;
            }
            else{
                i++;
            }
        }
        
        return nums.size()-count;
    }
};