class Solution {
public:
    string convertToBinary(int n){
        if(!n)
            return "0";
        string res = "";
        while(n){
            res += '0' + n%2;
            n /= 2;
        }
        return res;
    }

    bool hasAlternatingBits(int n) {
        string binary = convertToBinary(n);
        bool res = true;
        int len = binary.size();
        for(int i = 1; i < len; i++)
            res = res && binary[i-1]!=binary[i];
        return res;
    }
};
