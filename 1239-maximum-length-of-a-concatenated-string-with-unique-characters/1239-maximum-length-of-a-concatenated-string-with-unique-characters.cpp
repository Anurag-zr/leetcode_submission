#include<bits/stdc++.h>

class Solution {
public:
    
    int maxi=0;
    
    static int max(int a,int b){
        if(a>=b) return a;
        return b;
    }
    
    void dfs(int ind,vector<string> &arr,unordered_map<char,bool> &umap){
        
        for(int i=ind;i<arr.size();i++){
            
            if(isUnique(arr[i],umap)){
                for(auto c: arr[i]) umap[c]=true;
                // maxi= umap.size();
                // cout<<arr[i]<<" "<<maxi<<endl;
                // maxi = max(maxi,dfs(i+1,arr,umap));
                // cout<<arr[i]<<" "<<maxi<<endl;
                
                
                //-----------//
                maxi = max(maxi,umap.size());
                dfs(i+1,arr,umap);
                for(auto c: arr[i]) umap.erase(c);
            }
        }
        
        // cout<<maxi<<endl;
        // return maxi;
    }
    
    bool isUnique(string s, unordered_map<char,bool> &umap){
        
        bool allUnique = true;
        vector<bool> check(26,false);
        
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()){
                allUnique = false;
                break;
            }
            else if(check[s[i]-'a']==true){
                allUnique = false;
                break;
            }
            else{
                check[s[i]-'a']=true;   
            }
        }
     return allUnique;
        
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map<char,bool> umap;
        // int maxi = dfs(0,arr,umap);
        dfs(0,arr,umap);
        return maxi;
    }
};