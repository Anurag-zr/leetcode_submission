//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> ans(num);
        
        int size = num==K ? K : K+1;
        
        priority_queue<int,vector<int>,greater<int>> pq(arr,arr+size);
        
        // while(!pq.empty()){
        //     cout<<pq.top()<<" "<<endl;
        //     pq.pop();
        // }
        
        int j=0;
        for(int i=K+1;i<num;i++){
            ans[j++] = pq.top();
            // cout<<pq.top()<<" ";
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            ans[j++] = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends