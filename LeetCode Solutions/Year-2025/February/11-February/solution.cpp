class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int n = s.size(), m = part.size(), k;
            string res = "";
            for(int i = 0; i < n; i++){
                res += s[i];
                k = res.size();
                while(k>=m && res.substr(k-m, m)==part){
                    for(int j = 0; j < m; j++)
                        res.pop_back();
                    k = res.size();
                }
            }
            return res;
        }
    };