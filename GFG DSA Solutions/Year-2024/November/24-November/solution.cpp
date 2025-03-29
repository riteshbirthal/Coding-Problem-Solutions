// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum = 0, ans = INT_MIN;
        for(int x : arr){
            sum<0 ? sum = x : sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};