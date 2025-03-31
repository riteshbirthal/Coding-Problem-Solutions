class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int num = 0, ans = 0, n = s.size();
        char ch;
        unordered_map<char, int> u_mp;
        u_mp['a'] = 1, u_mp['e'] = 2, u_mp['i'] = 4, u_mp['o'] = 8, u_mp['u'] = 16;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            ch = s[i];
            if(u_mp.find(ch)!=u_mp.end()){
                num = num ^ u_mp[ch];
            }
            if(mp.find(num)!=mp.end()){
                ans = max(ans, i-mp[num]);
            }else if(u_mp.find(ch)!=u_mp.end()){
                mp[num] = i;
            }
        }
        return ans;
    }
};