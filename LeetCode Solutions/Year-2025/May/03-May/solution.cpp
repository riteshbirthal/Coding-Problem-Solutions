class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = tops[0], b = bottoms[0], n = tops.size(), res = 0, temp = 0;
        for(int i = 1; i < n; i++){
            if(a==tops[i]){
                if(b!=bottoms[i])
                    b = 0;
            }else if(a==bottoms[i]){
                if(b!=tops[i])
                    b = 0;
            }else if(b==tops[i]){
                if(a!=bottoms[i])
                    a = 0;
            }else if(b==bottoms[i]){
                if(a!=tops[i])
                    a = 0;
            }else{
                return -1;
            }
        }
        if(a==0 && b==0)
            return -1;
        if(a){
            res = INT_MAX, temp = 0;
            for(int i = 0; i < n; i++){
                temp += tops[i]!=a;
            }
            res = min(res, temp), temp = 0;
            for(int i = 0; i < n; i++){
                temp += bottoms[i]!=a;
            }
            res = min(res, temp);
        }else if(b){
            res = INT_MAX, temp = 0;
            for(int i = 0; i < n; i++){
                temp += tops[i]!=b;
            }
            res = min(res, temp), temp = 0;
            for(int i = 0; i < n; i++){
                temp += bottoms[i]!=b;
            }
            res = min(res, temp);
        }else{
            return -1;
        }
        return res;
    }
};