// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    if(n==1){
        if(arr[0]==x){
            return {0,0};
        }
        else{
            return {-1,-1};
        }
    }
    
    int start =0;
    int end =n-1;
    int mid;
    int firstoccurence =-1;
    
    while(start<=end){
        mid = start +(end-start)/2;
        if(arr[mid]==x){
            firstoccurence = mid;
            end = mid -1;
        }
        else if(x < arr[mid]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    
    start =0;
    end = n-1;
    int lastoccurence =-1;
    
    while(start<=end){
         mid = start +(end-start)/2;
        if(arr[mid]==x){
            lastoccurence= mid;
            start = mid +1;
        }
        else if(x < arr[mid]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }   
    }
    
    return {firstoccurence,lastoccurence};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends