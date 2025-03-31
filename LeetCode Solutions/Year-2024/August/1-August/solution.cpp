class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(details[i][11]>'6' || (details[i][11]=='6' && details[i][12]>'0'))
                ans++;
        }
        return ans;
    }
};