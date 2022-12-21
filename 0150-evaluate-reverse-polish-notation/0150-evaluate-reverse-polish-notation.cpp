#include<bits/stdc++.h>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for(auto op : tokens){
            if(op!="+" && op!="-" && op!="*" && op!="/"){
                // cout<<op<<endl;
                st.push(stoi(op));
                continue;
            }
            
            long long  op2 = st.top();st.pop();
            long long op1 = st.top(); st.pop();
            long long ans=0;
            
            if(op=="+"){
              ans = op1 + op2;   
            }
            
            if(op=="-"){
                ans = op1  - op2;
            }
            
            if(op=="*"){
                ans = op1 * op2;
            }
            
            if(op=="/"){
                ans = op1/op2;
            }
            
            st.push(ans);
        }
        
        
        return st.top();
    }
};