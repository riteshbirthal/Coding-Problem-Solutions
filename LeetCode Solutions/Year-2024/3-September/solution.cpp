class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size(), ans;
        string num = "";
        for(int i = 0; i < n; i++)
            num += to_string(s[i] - 'a' + 1);
        for(int i = 0; i < k; i++){
            ans = 0;
            for(auto x : num)
                ans += x - '0';
            num = to_string(ans);
        }
        return ans;
    }
};