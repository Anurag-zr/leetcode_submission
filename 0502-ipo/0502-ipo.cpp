class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); // no. of projects
        
        int capacity =w;  // capital capicity to perform project;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqCap;
        priority_queue<pair<int,int>> pqPro;
        for(int i=0;i<n;i++){
            pqCap.push({capital[i],profits[i]});
            // cout<<pqCap.top().first<<" "<<pqCap.top().second<<endl;
        }
        
        while(k>0){

            while(!pqCap.empty() && pqCap.top().first<=capacity){
                int cap = pqCap.top().first;
                int profit =pqCap.top().second;
                pqCap.pop();
                
                pqPro.push({profit,cap});
            }
            
            if(!pqPro.empty()){
                capacity+=pqPro.top().first;
                pqPro.pop();
                k--;
            }
            else break;
        }
        
        return capacity;
    }
};