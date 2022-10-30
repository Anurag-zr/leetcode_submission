class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        
        for(auto c:s){
            if(c>=65 && c<=90)
                str+= (c+32);
            else if((c>=97 && c<=122) || (c>=48 && c<=57))
                str+=c;
            
            else continue;
        }
        
        string revstr = str;
        reverse(revstr.begin(),revstr.end());
        
        return str==revstr;
    }
};