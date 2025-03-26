class Solution {
    public:
        bool checkNumber(string num, string currNum, int l, int n){
            if(n<0)
                return false;
            if(l==num.size())
                return currNum.size() ? stoi(currNum)==n : n==0;
            bool res = currNum.size() ? checkNumber(num, "", l, n-stoi(currNum)) : false;
            currNum += num[l];
            res = res || checkNumber(num, currNum, l+1, n);
            return res;
        }
    
        int punishmentNumber(int n) {
            int res = 0;
            for(int i = 1; i <= n; i++){
                res += checkNumber(to_string(i*i), "", 0, i) ? i*i : 0;
            }
            return res;
        }
    };