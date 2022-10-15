//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adjList[N];
	    
	    for(int i=0;i<prerequisites.size();i++){
	        int node = prerequisites[i].second;
	        adjList[node].push_back(prerequisites[i].first);
	    }
	    
	    vector<int> indegree(N,0);
	    
	    for(int i=0;i<prerequisites.size();i++){
	        indegree[prerequisites[i].first]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    int topoSize=0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topoSize++;
	        
	        for(auto adjNode :adjList[node]){
	            indegree[adjNode]--;
	            if(indegree[adjNode]==0) q.push(adjNode);
	        }
	        
	    }
	    
	    
	    if(topoSize == N) return true;
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends