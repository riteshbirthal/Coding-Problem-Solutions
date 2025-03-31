class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> num, den, den_;
        int n = expression.size(), sign = 0, flag = 1, c_n = 0, c_d = 0; // current numerator, current denominator
        for(int i = 0; i < n; i++){
            if(expression[i]=='-'){
                sign = 1;
                flag = 1;
                if(c_d)
                    den.push_back(c_d);
                c_d = 0;
            }else if(expression[i]=='+'){
                sign = 0;
                flag = 1;
                if(c_d)
                    den.push_back(c_d);
                c_d = 0;
            }else if(expression[i]=='/'){
                flag = 0;
                num.push_back(sign ? -1 * c_n : c_n);
                c_n = 0;
            }else if(flag){
                c_n  = c_n*10 + expression[i] - '0';
            }else{
                c_d  = c_d*10 + expression[i] - '0';
            }
        }
        if(c_d)
            den.push_back(c_d);
        n = num.size();
        int LCM = 1, div = 2, final_num = 0;
        den_ = den;
        while(div<8){
            flag = 1;
            for(int i = 0; i < n; i++){
                if(den[i]%div==0){
                    den[i] = den[i]/div;
                    flag = 0;
                    LCM *= div;
                }
            }
            if(flag)
                div++;
        }
        den = den_;
        for(int i = 0; i < n; i++){
            final_num += num[i] * (LCM/den[i]);
        }
        div = 2;
        while(div<8){
            flag = 1;
            if(final_num%div==0 && LCM%div==0){
                final_num /= div, LCM /= div;
                flag = 0;
            }
            if(flag)
                div++;
        }
        return to_string(final_num) + "/" + to_string(LCM);
    }
};