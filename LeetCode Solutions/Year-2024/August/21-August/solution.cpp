class Solution {
public:
    int func(string s, int l, int r, vector<vector<int>>& vec){
        if(l>r) return 0;
        if(l==r) return 1;
        if(vec[l][r]!=-1) return vec[l][r];
        int ans = INT_MAX, temp;
        char left = ' ', right = ' ';
        if(l) left = s[l-1];
        if(r<s.size()-1) right = s[r+1];
        for(int i = l; i <= r; i++){
            temp = s[i]==left || s[i]==right ? 0 : 1;
            ans = min(ans, func(s, l, i-1, vec) + func(s, i+1, r, vec) + temp);
        }
        return vec[l][r] = ans;
    }
    int strangePrinter(string s) {
        int n = s.size(), ans;
        string st = "";
        for(int i = 0; i < n; i++)
            if(st.size()==0 || st[st.size()-1]!=s[i])
                st += s[i];
        s = st, n = s.size();
        vector<vector<int>> vec(n, vector<int>(n, -1));
        ans = func(s, 0, n-1, vec);
        return ans;
    }
};