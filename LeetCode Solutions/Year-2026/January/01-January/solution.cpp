class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, new_num;
        for(int i = 0; i<digits.size(); i++){
            new_num = digits[i] + carry;
            carry = (digits[i] + carry)/10;
            digits[i] = new_num % 10;
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
