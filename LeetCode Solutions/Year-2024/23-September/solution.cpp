class Solution {
public:
    int func(string s, int n, int l, unordered_set<string>& u, vector<vector<int>>& vec){
        if(n+l>s.size() || n==s.size()) return 0;
        string st = s.substr(n, l);
        if(n+l==s.size()) return u.find(st)==u.end() ? l : 0;
        // cout << st << endl;
        if(vec[n][l]!=-1) return vec[n][l];
        if(u.find(st)!=u.end()){
            return vec[n][l] = min(func(s, n+l, 1, u, vec), func(s, n, l+1, u, vec));
        }
        return vec[n][l] = min(l + func(s, n+l, 1, u, vec), func(s, n, l+1, u, vec));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> u_set;
        vector<vector<int>> vec(n+2, vector<int>(n+2, -1));
        for(auto s : dictionary)
            u_set.insert(s);
        return func(s, 0, 1, u_set, vec);
    }
};