class Solution {
public:
    long long func(int n, int l, int a, vector<vector<vector<int>>>& vec){
        if(n==0) return 1;
        if(vec[n][l][a]!=-1) return vec[n][l][a];
        if(l==0){
            if(a){
                return vec[n][l][a] = (func(n-1, 2, a, vec) + func(n-1, 2, a-1, vec)) % (long long)(1e9 + 7);
            }else{
                return vec[n][l][a] = (func(n-1, 2, a, vec))  % (long long)(1e9 + 7);
            }
        }
        if(a){
            return vec[n][l][a] = (func(n-1, 2, a, vec) + func(n-1, l-1, a, vec) + func(n-1, 2, a-1, vec)) % (long long)(1e9 + 7);
        }else{
            return vec[n][l][a] = (func(n-1, 2, a, vec) + func(n-1, l-1, a, vec)) % (long long)(1e9 + 7);
        }
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> vec(n+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return func(n, 2, 1, vec);
    }
};