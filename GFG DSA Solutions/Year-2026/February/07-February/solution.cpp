class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int res = 0, n = arr.size(), sum = -arr[0], curr;
        for(int i = 0; i < n; i++)
            res += i*arr[i], sum += arr[i];
        curr = res;
        for(int i = 1; i < n; i++){
            sum += arr[(n-i+1)%n]-arr[n-i];
            curr += sum - (n-1)*arr[n-i];
            res = max(res, curr);
        }
        return res;
    }
};
