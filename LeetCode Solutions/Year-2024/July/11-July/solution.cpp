class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string> st;
        string temp;
        st.push("");
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                st.push("");
            }else if(s[i]==')'){
                temp = st.top();
                st.pop();
                reverse(temp.begin(), temp.end());
                st.top() += temp;
            }else{
                st.top() += s[i];
            }
        }
        return st.top();
    }
};