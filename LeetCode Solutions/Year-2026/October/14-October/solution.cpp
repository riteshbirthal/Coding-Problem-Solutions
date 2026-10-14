class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        for(int i = num; i ; i--){
            if(sum){
                res += '0' + min(9, sum);
                sum -= min(9, sum);
            }else
                res += '0';
        }
        if(sum)
            return "";
        return res;
    }
};
