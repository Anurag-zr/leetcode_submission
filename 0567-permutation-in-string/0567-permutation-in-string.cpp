class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.length();
        int m = s2.length();
        
        if(n>m) return false;
        
        sort(s1.begin(),s1.end());
        
        int i=0;
        for(int j=0;j<s2.length();j++){
            
            if(j-i+1==n){
                string temp = s2.substr(i,j-i+1);
                sort(temp.begin(),temp.end());
                
                if(s1 == temp) return true;
                else i++;
            }
        }
        
        return false;
    }
};