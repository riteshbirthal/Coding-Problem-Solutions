class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0, curr_xor = 0;
        for(int i = 0; i < n; i++){
            curr_xor ^= arr[i];
            if(i<k-1)
                continue;
            res = max(res, curr_xor);
            curr_xor ^= arr[i-k+1];
        }
        return res;
    }
};
