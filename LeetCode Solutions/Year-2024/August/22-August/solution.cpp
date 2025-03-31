class Solution {
public:
    int findComplement(int num) {
        int idx = 31;
        for(int i = 31; i >= 0; i--){
            if(num&(1<<i))
                break;
            idx--;
        }
        for(int i = idx; i >= 0; i--){
            if(num&(1<<i))
                num -= (1<<i);
            else
                num += (1<<i);
        }
        return num;
    }
};