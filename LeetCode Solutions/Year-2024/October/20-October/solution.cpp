class Solution {
public:
    pair<int, bool> func(string ex, int n){
        int sign = ex[n]=='!' ? 0 : ex[n]=='|' ? 1 : 2;
        if(sign==0){
            if(ex[n+2]!='t' && ex[n+2]!='f'){
                pair<int, bool> pr = func(ex, n+2);
                return {pr.first + 3, !pr.second};
            }
            return {4, ex[n+2]=='t' ? false : true};
        }
        int siz = ex.size(), len = 2, flag = 1;
        bool ans = sign==1 ? false : true;
        pair<int, bool> pr;
        for(int i = n+2; i < siz && flag; i++){
            if(ex[i]=='t' || ex[i]=='f'){
                sign==1 ? ans |= (ex[i]=='t' ? true : false) : ans &= (ex[i]=='t' ? true : false);
                len++;
            }else if(ex[i] == ','){
                len++;
            }else if(ex[i]==')'){
                len++, flag = 0;
            }else{
                pr = func(ex, i);
                sign==1 ? ans |= pr.second : ans &= pr.second;
                i += pr.first - 1;
                len += pr.first;
            }
        }
        return {len, ans};
    }
    bool parseBoolExpr(string expression) {
        bool ans = func(expression, 0).second;
        return ans;
    }
};