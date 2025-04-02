class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        pair<char, int> pr;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('){
                pr.first = '(';
                pr.second = i;
                st.push(pr);
            }else if(s[i]==')'){
                if(!st.empty() && st.top().first=='(') st.pop();
                else{
                    pr.first = ')';
                    pr.second = i;
                    st.push(pr);
                }
            }
        }
        while(!st.empty()){
            s.erase(st.top().second, 1);
            st.pop();
        }
        return s;
    }
};