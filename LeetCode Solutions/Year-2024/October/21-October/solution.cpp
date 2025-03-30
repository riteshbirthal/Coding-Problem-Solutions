class Solution {
public:
    int func(string s, string curr, int n, unordered_set<string>& u){
        if(n==s.size()) return curr.size()==0 ? 0 : INT_MIN;
        int ans = 0;
        curr += s[n];
        if(u.find(curr)==u.end()){
            u.insert(curr);
            ans = max(ans, 1 + func(s, "", n+1, u));
            u.erase(curr);
            ans = max(ans, func(s, curr, n+1, u));
        }else{
            ans = max(ans, func(s, curr, n+1, u));
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        string st = "";
        unordered_set<string> u;
        return func(s, st, 0, u);
    }
};