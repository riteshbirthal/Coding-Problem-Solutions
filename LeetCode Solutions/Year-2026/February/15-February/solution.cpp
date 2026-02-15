class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = "";
        int carry = 0, i = 0, j = 0, num;
        while(i<a.size() || j < b.size()){
            num = carry;
            if(i<a.size()) num += a[i] - '0';
            if(j<b.size()) num += b[j] - '0';
            c.push_back('0' + num%2);
            carry = num/2;
            i++, j++;
        }
        if(carry) c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
    }
};
