class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            while(ans.size() && num[i]<ans[ans.size()-1] && k){
                k--;
                ans.pop_back();
            }
            if(ans.size() || (ans.size()==0 && num[i]!='0')) ans += num[i];
        }
        while(k && ans.size())
            ans.pop_back(), k--;
        if(ans.size()==0) ans = "0";
        return ans;
    }
};