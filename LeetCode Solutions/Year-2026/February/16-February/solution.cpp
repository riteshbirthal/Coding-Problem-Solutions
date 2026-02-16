class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool sign = false;
        if(n<0) sign = true;
        if(sign) n *= -1;
        uint32_t ans = 0;
        for(int i = 0; i <32; i++){
            if(uint32_t(pow(2, i)) & n) ans |= uint32_t(pow(2, 31-i));
        }
        if(sign) ans *= -1;
        return ans;
    }
};
