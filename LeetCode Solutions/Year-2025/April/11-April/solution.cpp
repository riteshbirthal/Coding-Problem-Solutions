class Solution {
public:
    bool isSymmetric(int n){
        string num = to_string(n);
        if(num.size()%2)
            return false;
        int firstHalf = 0, secondHalf = 0, m = num.size();
        for(int i = 0; i < m/2; i++){
            firstHalf += num[i]-'0';
            secondHalf += num[m-i-1]-'0';
        }
        return firstHalf==secondHalf;
    }
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int i = low; i <= high; i++){
            res += isSymmetric(i);
        }
        return res;
    }
};
