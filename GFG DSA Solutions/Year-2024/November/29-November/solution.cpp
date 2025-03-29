// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans = "", num1 = s1, num2 = s2;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while(num1.size() && num1[num1.size()-1]=='0')
            num1.pop_back();
        while(num2.size() && num2[num2.size()-1]=='0')
            num2.pop_back();
        int carry = 0, n1 = num1.size(), n2 = num2.size(), idx1 = 0, idx2 = 0;
        while(idx1<n1 && idx2<n2){
            ans.push_back((num1[idx1] + num2[idx2] + carry - '0' - '0')%2 + '0');
            carry = (num1[idx1] + num2[idx2] + carry - '0' - '0')/2;
            idx1++, idx2++;
        }
        while(idx1<n1){
            ans.push_back((num1[idx1] -'0' + carry)%2 + '0');
            carry = (num1[idx1] - '0' + carry)/2;
            idx1++;
        }
        while(idx2<n2){
            ans.push_back((num2[idx2] -'0' + carry)%2 + '0');
            carry = (num2[idx2] - '0' + carry)/2;
            idx2++;
        }
        if(carry) ans.push_back(carry + '0');
        if(!ans.size()) ans = "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};