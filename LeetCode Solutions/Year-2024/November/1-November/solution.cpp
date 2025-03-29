class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n;
        for(auto ch: s){
            n = ans.size();
            if((n>1 && (ans[n-1]!=ch || ans[n-2]!=ch)) || n<2){
                ans += ch;
            }
        }
        return ans;
    }
};