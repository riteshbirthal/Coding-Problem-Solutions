class Solution {
public:
    int numSteps(string s) {
        int ans = 0, idx;
        while(s.size()!=1){
            if(s[s.size()-1]=='0') s.pop_back();
            else{
                idx = s.size() - 1;
                while(idx>=0 && s[idx]=='1'){
                    s[idx] = '0';
                    idx--;
                }
                if(idx==-1) s = "1" + s;
                else s[idx] = '1';
            }
            ans++;
        }
        return ans;
    }
};
