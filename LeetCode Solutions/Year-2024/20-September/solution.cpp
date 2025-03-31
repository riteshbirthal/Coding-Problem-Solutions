class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;
        
        vector<int> lps(combined.size(), 0);
        for (int i = 1; i < combined.size(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }
        int add_len = s.size() - lps.back();
        string add_str = rev_s.substr(0, add_len);
        return add_str + s;
    }
};
