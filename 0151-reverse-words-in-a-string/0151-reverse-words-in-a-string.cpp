class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str;
        stringstream ss(s);
        
        while(ss>>str){
            st.push(str);
        }
        
        string ans ="";
        
        while(!st.empty()){
            ans+= st.top()+' ';
            st.pop();
        }
        
        ans = ans.substr(0,ans.length()-1);
        
        return ans;
    }
};