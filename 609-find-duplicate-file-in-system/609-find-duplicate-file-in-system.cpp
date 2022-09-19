class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        vector<vector<string>> ans;
        
        for(auto path:paths){
            stringstream ss(path);  // or ss<<path;
            string root="";
            
            getline(ss,root,' ');
            
            string str="";
            
            while(getline(ss,str,' ')){
                string fileName = root+'/'+str.substr(0,str.find('('));
                string fileContent = str.substr(str.find('(')+1,str.find(')')-str.find('(')-1);
                
                
                files[fileContent].push_back(fileName);
            }
            
        }
        
        
        for(auto file:files){
            if(file.second.size()>1){
                ans.push_back(file.second);
            }
        }
        
        
        return ans;
    }
};