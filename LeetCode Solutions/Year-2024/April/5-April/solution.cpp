class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(ans.size()){
                if(s[i]>='a' && s[i]<='z'){
                    if(ans[ans.size()-1]>='A' && ans[ans.size()-1]<='Z' && int(ans[ans.size()-1]-'A')==int(s[i]-'a')){
                        ans.pop_back();
                    }else ans = ans + s[i];
                }else if(s[i]>='A' && s[i]<='Z'){
                    if(ans[ans.size()-1]>='a' && ans[ans.size()-1]<='z' && int(ans[ans.size()-1]-'a')==int(s[i]-'A')){
                        ans.pop_back();
                    }else ans = ans + s[i];
                }
            }else ans = ans + s[i];
        }
        return ans;
    }
};