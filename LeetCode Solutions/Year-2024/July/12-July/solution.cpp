class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string st = "";
        int ans = 0, n = s.size();
        if(x>=y){
            for(int i = 0; i < n; i++){
                if(s[i]=='b' && !st.empty() && st[st.size()-1]=='a'){
                    st.pop_back(), ans += x;
                }else{
                    st.push_back(s[i]);
                }
            }
            s = st, st = "", n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i]=='a' && !st.empty() && st[st.size()-1]=='b'){
                    st.pop_back(), ans += y;
                }else{
                    st.push_back(s[i]);
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                if(s[i]=='a' && !st.empty() && st[st.size()-1]=='b'){
                    st.pop_back(), ans += y;
                }else{
                    st.push_back(s[i]);
                }
            }
            s = st, st = "", n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i]=='b' && !st.empty() && st[st.size()-1]=='a'){
                    st.pop_back(), ans += x;
                }else{
                    st.push_back(s[i]);
                }
            }
        }
        if(ans==0) return ans;
        return ans + maximumGain(st, x, y);
    }
};