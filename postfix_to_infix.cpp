int n = exp.length();
        stack<string> st;
        for(int i=0;i<n;i++){
            char ch = exp[i];
            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
                st.push(string(1,ch));
            }
            else{
                string s2=st.top();
                st.pop();
                string s1=st.top();
                st.pop();
                st.push('(' + s1 + ch + s2 + ')');
            }
        }
        return st.top();