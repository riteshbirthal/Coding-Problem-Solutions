class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          // Your code here
          sort(arr.begin(), arr.end());
          int n = arr.size();
          vector<int> res(arr.begin()+n-k, arr.end());
          reverse(res.begin(), res.end());
          return res;
      }
  };