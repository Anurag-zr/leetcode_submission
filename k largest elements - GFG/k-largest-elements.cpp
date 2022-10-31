//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans(k);
	    
	    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+k);
	    
	   // while(!pq.empty()){
	   //     cout<<pq.top()<<endl;
	   //     pq.pop();
	   // }
	   
	   
	   for(int i=k;i<n;i++){
	       int smallest = pq.top();
	       if(arr[i]>smallest){
	           pq.pop();
	           pq.push(arr[i]);
	       }
	   }
	   
	   
	   int index = k-1;
	   while(!pq.empty()){
	       ans[index--]= pq.top();
	       pq.pop();
	   }
	   

	    return ans;
	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends