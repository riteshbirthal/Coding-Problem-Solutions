class Solution {
    public:
        string func(string st, string pattern, int idx, vector<int>& v){
            if(idx==pattern.size())
                return st;
            string res = "";
            if(pattern[idx]=='I'){
                for(char ch = st[idx]+1; ch <= '9'; ch++){
                    if(v[ch-'0']){
                        v[ch-'0'] = 0;
                        res = func(st + ch, pattern, idx+1, v);
                        if(res.size())
                            return res;
                        v[ch-'0'] = 1;
                    }
                }
            }else{
                for(char ch = st[idx]-1; ch >= '1'; ch--){
                    if(v[ch-'0']){
                        v[ch-'0'] = 0;
                        res = func(st + ch, pattern, idx+1, v);
                        if(res.size())
                            return res;
                        v[ch-'0'] = 1;
                    }
                }
            }
            return res;
        }
        string smallestNumber(string pattern) {
            string res = "";
            vector<int> v(10, 0);
            for(int i = 1; i <= pattern.size()+1; i++)
                v[i] = 1;
            for(int i = 1; i <= 9; i++){
                v[i] = 0;
                res = func(to_string(i), pattern, 0, v);
                if(res.size())
                    return res;
                v[i] = 1;
            }
            return res;
        }
    };