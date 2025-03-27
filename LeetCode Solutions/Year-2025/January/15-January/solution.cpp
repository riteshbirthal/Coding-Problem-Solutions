class Solution {
    public:
        int minimizeXor(int num1, int num2) {
            int res = 0, count1 = 0, count2 = 0, n1 = num1, n2 = num2;
            while(n1 || n2){
                count1 += (n1&1), count2 += (n2&1);
                n1 = n1 >> 1, n2 = n2 >> 1;
            }
            res = num1;
            while(count1!=count2){
                for(int i = 0; i < 32; i++){
                    if(count1>count2 && (res&(1<<i))==(1<<i)){
                        res -= (1<<i);
                        break;
                    }else if(count1<count2 && (res&(1<<i))==0){
                        res += (1<<i);
                        break;
                    }
                }
                count1>count2 ? count1-- : count1++;
            }
            return res;
        }
    };