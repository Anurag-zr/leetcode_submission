my first attempt answer wonderful!!!
logic is correct but not optimized O(n^2) complexity
o(nlogn) required complexity using 2 priority queue..... super helpful
​
here is my code
​
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
int n = profits.size(); // no. of projects
int capacity =w;  // capital capicity to perform project;
vector<int> vis(n,0);
while(k>0){
int maxProfit =-1e9;
int selProjInd = -1;
for(int ithP = 0;ithP<n;ithP++){
if(capital[ithP]> capacity) continue;
if(vis[ithP]) continue;
if(profits[ithP]> maxProfit){
maxProfit = profits[ithP];
selProjInd = ithP;
}
}
if(selProjInd!=-1){
capacity+=maxProfit;
vis[selProjInd]=1;
k--;
}
else break;
}
return capacity;
}