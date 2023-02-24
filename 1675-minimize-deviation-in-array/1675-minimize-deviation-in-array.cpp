class Solution {
public:
//     int minimumDeviation(vector<int>& nums) {
//         int ans = 1e9;
//         int mini = 1e9;
        
//         priority_queue<int> pq;
        
//         for(auto n: nums){
//             if(n%2) n = n*2;
//             pq.push(n);
//             mini = min(mini,n);
//         }
        
//         while(pq.top()%2==0){
//             ans = min(ans,pq.top()-mini);
//             mini = min(mini,pq.top()/2);
//             pq.push(pq.top()/2);
//             pq.pop();
//         }
        
//         return min(ans,pq.top()-mini);
//     }
    
    //solution 2 using set data structure
    
        int minimumDeviation(vector<int>& nums) {
        int ans = 1e9;
        int mini = 1e9;
        
        set<int> st;
        
        for(auto n: nums){
            if(n%2) n = n*2;
            st.insert(n);
            mini = min(mini,n);
        }
        
        while(*st.rbegin()%2==0){
            int x = *st.rbegin();
            st.erase(x);
            
            ans = min(ans,x-mini);
            mini = min(mini,x/2);
            st.insert(x/2);
        }
        
        return min(ans,*st.rbegin()-mini);
    }
};