class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), l_a = 0, l_b = 0, r_a = 0, r_b = 0, ans = INT_MAX;
        vector<vector<int>> vec(n, {0, 0, 0, 0}); //left a's, left b's, right a's, right b's
        for(int i = 0; i < n; i++){
            if(s[i]=='a')
                vec[i][0] = l_a, l_a++, vec[i][1] = l_b;
            else
                vec[i][1] = l_b, l_b++, vec[i][0] = l_a;
            if(s[n-1-i]=='a')
                vec[n-1-i][2] = r_a, r_a++, vec[n-i-1][3] = r_b;
            else
                vec[n-1-i][3] = r_b, r_b++, vec[n-i-1][2] = r_a;
        }
        for(int i = 0; i < n; i++){
            if(s[i]=='a')
                ans = min(ans, vec[i][1] + vec[i][3]);
            else
                ans = min(ans, vec[i][1] + vec[i][2]);
        }
        return ans;
    }
};