class Solution {
public:
    int minOps(string s, bool isOne){
        int res = 0, n = s.size();
        string st = "";
        for(int i = 0; i < n; i++){
            st += isOne ? '1' : '0';
            isOne = !isOne;
        }
        for(int i = 0; i < n; i++)
            res += st[i]!=s[i];
        return res;
    }
    int minOperations(string s) {
        int n = s.size(), res;
        res = min(minOps(s, true), minOps(s, false)); 
        return res;
    }
};
