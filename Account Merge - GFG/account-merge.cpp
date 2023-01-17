//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class  DisjointSet{
    public: 
      vector<int> parent;
      vector<int> size;
      
    public:
       
       DisjointSet(int n){
           parent.resize(n+1);
           size.resize(n+1,1);
           
           for(int i=0;i<=n;i++) parent[i]=i;
       }
       
       
       int findUParent(int u){
           if(parent[u]==u) return u;
           
           return parent[u] = findUParent(parent[u]);
       }
       
       void unionBySize(int u,int v){
           int upu = findUParent(u);
           int upv = findUParent(v);
           
           if(upu==upv) return;
           
           if(size[upu]< size[upv]){
               parent[upu]= upv;
               size[upv]+=size[upu];
           }
           
           if(size[upv]<=size[upu]){
               parent[upv]=upu;
               size[upu]+=size[upv];
           }
       }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
                int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string,int> umap;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(umap.find(accounts[i][j])==umap.end()){ //if email don't exist in map
                    umap[accounts[i][j]]=i;
                }   
                else{
                    //exist already i.e this email must be a part of other user
                    int parent = umap[accounts[i][j]];
                    ds.unionBySize(parent,i);
                }
            }
        }
        
        vector<vector<string>> temp(n,vector<string>());
        
        for(auto it: umap){
            string key = it.first;
            int val = it.second;
            
            temp[ds.findUParent(val)].push_back(key);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<temp.size();i++){
            vector<string> details;
            if(temp[i].size()!=0) {
                details.push_back(accounts[i][0]);
                sort(temp[i].begin(),temp[i].end());
                details.insert(details.begin()+1,temp[i].begin(),temp[i].end());
            }
            
            if(details.size()) ans.push_back(details);
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends