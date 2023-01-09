//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
     vector<int> stepsDis(1e5,1e9);
     stepsDis[start]=0;
     
     queue<pair<int,int>> q;
     q.push({0,start});
     
     while(!q.empty()){
         pair<int,int> pr = q.front();
         int steps = pr.first;
         int node = pr.second;
         q.pop();
         
         if(node == end) return steps;
         
         for(auto i: arr){
             int adjNode = (i*node)% (int)1e5;
             if(stepsDis[node]+1<stepsDis[adjNode]){
                 stepsDis[adjNode]=stepsDis[node]+1;
                 q.push({stepsDis[adjNode],adjNode});
             }
         }
     }
     
     return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends