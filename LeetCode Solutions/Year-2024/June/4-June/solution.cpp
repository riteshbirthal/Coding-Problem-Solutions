class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 1, n = s.size();
        vector<int> vec(52, 0);
        for(int i = 0; i < n; i++)
            if(s[i]<='z' && s[i]>='a')
                vec[s[i]-'a']++;
            else
                vec[s[i]-'A'+26]++;
        for(int i = 0; i < 52; i++)
            ans += (vec[i]/2)*2;
        return min(ans, n);
    }
};