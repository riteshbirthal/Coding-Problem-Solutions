class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), res = 0, curr = 0;
        for(int i = 0; i < n; i++){
            curr += arr[i];
            if(i < k-1)
                continue;
            res = max(res, curr);
            curr -= arr[i-k+1];
        }
        return res;
    }
};
