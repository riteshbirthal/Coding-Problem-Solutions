class Solution {
public:
    int func(string s, int a, int n, vector<vector<int>>& vec){
        if(a<0) return false;
        if(n==s.size()) return a==0 ? 1 : 0;
        if(s[n]==')' && a==0) return vec[a][n] = 0;
        if(vec[a][n]!=-1) return vec[a][n];
        else if(s[n]==')') return vec[a][n] = func(s, a-1, n+1, vec) ? 1 : 0;
        else if(s[n]=='(') return vec[a][n] = func(s, a+1, n+1, vec) ? 1 : 0;
        else return vec[a][n] = func(s, a, n+1, vec) || func(s, a+1, n+1, vec) || func(s, a-1, n+1, vec) ? 1 : 0;
    }
    bool checkValidString(string s) {
        vector<vector<int>> vec(s.size()+1, vector<int>(s.size()+1, -1));
        return func(s, 0, 0, vec);
    }
};