#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second>b.second; //smaller value stay at top
    else return a.first<b.first; //higher frequency stay at top
}

void sortAccToFrq(vector<int> &arr,int n){
    unordered_map<int,int> umap;
    
    for(auto i:arr){
        umap[i]++;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&compare)> pq(compare);
    
    for(auto it:umap){
        pq.push({it.second,it.first});
    }
    
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        
        while(p.first--){
            cout<<p.second<<" ";
        }
    }
    
    cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    sortAccToFrq(arr,n);
	}
	return 0;
}