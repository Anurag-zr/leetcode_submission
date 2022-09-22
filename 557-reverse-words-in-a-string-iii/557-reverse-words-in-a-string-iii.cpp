class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        s="";
        string str;
        while(getline(ss,str,' ')){
            reverse(str.begin(),str.end());
            s+=str+' ';
        }
         s = s.substr(0,s.length()-1);
        
        return s;
    }
};