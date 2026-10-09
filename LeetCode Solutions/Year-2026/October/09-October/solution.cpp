class Solution {
public:
    int minInsertions(string s) {
        int res = 0, n = s.size();
        string n_s = "";
        for(char c : s){
            int m = n_s.size();
            if(m>1 && n_s[m-2]=='(' && n_s[m-1]==')' && c==')')
                n_s.pop_back(), n_s.pop_back();
            else if(m>1 && n_s[m-2]=='(' && n_s[m-1]==')' && c=='(')
                n_s.pop_back(), n_s.pop_back(), res++, n_s += c;
            else if(m && n_s[m-1]==')' && c=='(')
                res += (m+1)/2 + m%2, n_s = "(";
            else
                n_s += c;
        }
        n = n_s.size();
        if(n>1 && n_s[n-2]=='(' && n_s[n-1]==')')
            n_s.pop_back(), n_s.pop_back(), res += 1;
        n = n_s.size();
        if(n && n_s[n-1]=='(')
            res += n*2;
        else
            res += (n+1)/2 + n%2;
        return res;
    }
};
