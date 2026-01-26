class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size(), even = 0, odd = 0, res = 0, prev_even = 0, prev_odd = 0;
        for(int i = 0; i < n; i++)
            i%2 ? even += arr[i] : odd += arr[i];
        for(int i = 0; i < n; i++){
            if(i)
                (i-1)%2 ? prev_even += arr[i-1] : prev_odd += arr[i-1];
            i%2 ? even -= arr[i] : odd -= arr[i];
            res += (prev_even + odd)==(prev_odd + even);
        }
        return res;
    }
};
