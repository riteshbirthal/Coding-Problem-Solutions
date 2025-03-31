class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> u1, u2;
        string st = "";
        for(auto ch : s1){
            if(ch==' '){
                if(st.size()){
                    u1[st]++;
                    st = "";
                }
            }else{
                st += ch;
            }
        }
        st.size() ? u1[st]++, st = "" : st = "";
        for(auto ch : s2){
            if(ch==' '){
                if(st.size()){
                    u2[st]++;
                    st = "";
                }
            }else{
                st += ch;
            }
        }
        st.size() ? u2[st]++, st = "" : st = "";
        for(auto s = u1.begin(); s != u1.end(); s++){
            if(u2.find(s->first)==u2.end() && s->second==1)
                ans.push_back(s->first);
        }
        for(auto s = u2.begin(); s != u2.end(); s++){
            if(u1.find(s->first)==u1.end() && s->second==1)
                ans.push_back(s->first);
        }
        return ans;
    }
};