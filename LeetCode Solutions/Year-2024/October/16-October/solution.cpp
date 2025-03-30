class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string st = "";
        // func(a, b, c, 0, 0, 0, "", st, a, b, c);
        int size = a + b + c;
        int A = 0, B = 0, C = 0;
        for(int i = 0; i<size; i++){
            if((a>=b && a>=c && A!=2) || (B==2 && a>0) || (C==2 && a>0)){
                st += 'a';
                a--, A++, B = 0, C = 0;
            }else if((b>=a && b>=c && B!=2) || (A==2 && b>0) || (C==2 && b>0)){
                st += 'b';
                b--, B++, A = 0, C = 0;
            }else if((c>=b && c>=a && C!=2) || (B==2 && c>0) || (A==2 && c>0)){
                st += 'c';
                c--, C++, B = 0, A = 0;
            }
        }
        return st;
    }
    // void func(int a, int b, int c, int p, int q, int r, string s, string & ans, int A, int B, int C){
    //     if(p>=3 || q>=3 || r>=3) return ;
    //     if(!a && !b && !c){
    //         if(ans.size()<s.size()) ans = s; 
    //             return ;
    //     }
    //     if(dp[a][b][c]!="x"){
    //         string t = s + dp[a][b][c];
    //         if(t.size()>ans.size()) ans = t;
    //         dp[a][b][c] = ans;
    //         return ;
    //     }
    //     if((a<A || !A) && (b<B || !B) && (c<C || !C) && ans.size()<s.size()) ans = s;
    //     if(a) func(a-1, b, c, p+1, 0, 0, s + 'a', ans, A, B, C);
    //     if(b) func(a, b-1, c, 0, q+1, 0, s + 'b', ans, A, B, C);
    //     if(c) func(a, b, c-1, 0, 0, r+1, s + 'c', ans, A, B, C);
    //     dp[a][b][c] = ans;
    // }
};