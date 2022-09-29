class Solution {
public:
    int lengthOfLastWord(string s) {
        string str;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            else{
                str="";
                while(i<s.length() && s[i]!=' '){
                    str+=s[i];
                    i++;
                }
            }
        }
         
        return str.length();
    }
};