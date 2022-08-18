class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int arrSize = arr.size();
        unordered_map<int,int> freq;
        for(auto ele:arr){
            freq[ele]++;
        }
        
        sort(arr.begin(),arr.end(), [&freq](int a , int b){
            if(freq[a]!=freq[b])
                return freq[a]>freq[b];
            return a<b;
        });
        
        int setSize=arrSize;
        int ans=0;
        for(int i=0;i<arrSize;){
            int ele= arr[i];
            int count = freq[ele];
            setSize-=count;
            // cout<<setSize<<" "<<arrSize/2<<endl;
            ans++;
            if(setSize<=arrSize/2){
                break;
            }
            i=i+count;
        }
        
        return ans;
    }
};