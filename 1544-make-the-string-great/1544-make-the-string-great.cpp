class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
         
            if(!st.empty() && (st.top()^32)==s[i]){
                // cout<<st.top()<<endl;
                st.pop();
            }
            else{
                // cout<<"push"<<s[i]<<endl;
                st.push(s[i]);
            }
            
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};