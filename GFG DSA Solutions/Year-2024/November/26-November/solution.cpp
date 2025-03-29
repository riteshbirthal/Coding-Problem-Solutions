class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int ans = INT_MIN, n = arr.size(), sum = 0, mx = INT_MIN;
        for(auto x : arr){
            sum = sum<=0 ? x : sum + x;
            ans = max(ans, sum);
        }
        sum = 0;
        vector<int> vec = {0};
        for(auto x : arr){
            sum += x;
            mx = max(mx, sum);
            vec.push_back(mx);
        }
        sum = 0;
        for(int i = n-1; i > 0; i--){
            sum += arr[i];
            ans = max(ans, sum + vec[i]);
        }
        return ans;
    }
};