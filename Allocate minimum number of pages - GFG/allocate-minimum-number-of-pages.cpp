// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int arr[],int n,int m,int curr_min){
        int curr_sum=0;
        int studentRequired = 1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>curr_min){
                return false;
            }
            
            if(curr_sum + arr[i] > curr_min){
                studentRequired++;
                curr_sum=arr[i];
                
               if(studentRequired>m){
                 return false;
                }
            }
            else{
               curr_sum+=arr[i];
            }
            
           
            
        }
        
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        
        long long sum = 0;
        if(n<m){
            return -1;
        }
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        int start=0, end=sum;
        int result = INT_MAX;
        
        
        while(start<=end){
            
            int mid = start +(end-start)/2;
            
            if(isPossible(arr,n,m,mid)){
                result = mid;
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends