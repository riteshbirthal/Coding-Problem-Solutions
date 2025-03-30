class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int mid_idx = pow(2, n-1);
        if(k==mid_idx) return '1';
        if(k<mid_idx){
            return findKthBit(n-1, k);
        }
        return findKthBit(n-1, pow(2, n) - k)=='1' ? '0' : '1';
    }
};