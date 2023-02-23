class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); // no. of projects
        
        int capacity =w;  // capital capicity to perform project;
        
        vector<pair<int,int>> project;
        for(int i=0;i<n;i++){
            project.push_back({capital[i],profits[i]});
        }
        
        sort(project.begin(),project.end(),[](pair<int,int> a,pair<int,int> b)->bool{
            return a.first<b.first;
        });
            
        
        priority_queue<int> pqPro; //maxHeap
        // for(int i=0;i<n;i++){
        //     pqCap.push({capital[i],profits[i]});
        //     // cout<<pqCap.top().first<<" "<<pqCap.top().second<<endl;
        // }
        
        int i=0;
        
        while(k>0){

            while(i<n && project[i].first<=capacity){
                pqPro.push(project[i++].second);
            }
            
            if(!pqPro.empty()){
                capacity+=pqPro.top();
                pqPro.pop();
                k--;
            }
            else break;
        }
        
        return capacity;
    }
};