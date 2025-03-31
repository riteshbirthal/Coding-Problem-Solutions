class Solution {
public:
    vector<string> ones, tens, tens_st;
    string func(int n){
        cout << n << endl;
        if(n==0) return "Zero";
        string ans = "", out;
        if(n/100){
            ans = ones[n/100] + " Hundred";
            out += func(n%100);
            if(out != "Zero")
                ans = ans.size() ? ans + " " + out : out;
        }else if((n%100)/10){
            if((n%100)/10 == 1){
                ans = ans.size() ? ans + " " + tens[((n%100)/10)%10] : tens[(n%100)%10];
            }else{
                ans = ans.size() ? ans + " " + tens_st[((n%100)/10)%10] : tens_st[((n%100)/10)%10];
                out += func(n%10);
                if(out != "Zero")
                    ans = ans.size() ? ans + " " + out : out;
            }
        }else if(n%10){
            ans += ones[n%10];
        }
        return ans;
    }
    string numberToWords(int num) {
        long long new_num = num;
        string ans = "", out;
        vector<string> vec{"Billion", "Million", "Thousand"};
        ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        tens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        tens_st = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        for(int i = 0; i < 4; i++){
            new_num = num % (long long) pow(10, 3 * (4 - i));
            new_num = new_num / pow(10, 3 * (3 - i) );
            out = func(new_num);
            if(out != "Zero")
                ans = ans.size() ? (i < 3 ? ans + " " + out + " " + vec[i] : ans + " " + out) : (i < 3 ? out + " " + vec[i] : out); 
        }
        if(ans.size()==0) ans = "Zero";
        return ans;
    }
};