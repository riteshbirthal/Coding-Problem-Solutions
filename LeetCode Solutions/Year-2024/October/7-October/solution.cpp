class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch=='B' && st.size() && st.top()=='A')
                st.pop();
            else if(ch=='D' && st.size() && st.top()=='C')
                st.pop();
            else
                st.push(ch);
        }
        return st.size();
    }
};