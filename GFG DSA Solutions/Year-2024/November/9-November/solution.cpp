// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int flag = 1;
        string num1 = "", num2 = "", ans = "";
        for(auto x : arr){
            if(flag)
                num1 += !num1.size() && x==0 ? "" : to_string(x);
            else
                num2 += !num2.size() && x==0 ? "" : to_string(x);
            flag = !flag;
        }
        int n1 = num1.size(), n2 = num2.size(), carry = 0, n;
        while(n1 && n2){
            n = num1[n1-1]-'0' + num2[n2-1]-'0' + carry;
            ans += to_string(n%10);
            carry = n/10;
            n1--, n2--;
        }
        while(n1){
            n = num1[n1-1]-'0' + carry;
            ans += to_string(n%10);
            carry = n/10;
            n1--;
        }
        while(n2){
            n = num2[n2-1]-'0' + carry;
            ans += to_string(n%10);
            carry = n/10;
            n2--;
        }
        if(carry) ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};