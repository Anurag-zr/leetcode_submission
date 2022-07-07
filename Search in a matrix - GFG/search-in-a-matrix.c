// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int matSearch (int N, int M, int arr[][M], int x)
{
    int i=0;
    int j=M-1;
    
    if(N==0 || M==0){
        return 0;
    }
    
    while(i>=0 && i<N && j>=0 && j<M){
        if(arr[i][j]==x){
            return 1;
        }
        else if(x<arr[i][j]){
            j--;
        }
        else if(x>arr[i][j]){
            i++;
        }
    }
    
    return 0;
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--)
	{
        int n, m;
		scanf("%d", &n);
		scanf("%d", &m);
		int matrix[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		   
		int x;
		scanf("%d", &x);
		
        int result = matSearch (n, m, matrix, x);
        printf("%d", result);
		printf("\n");
    }
    return 0;
}
  // } Driver Code Ends