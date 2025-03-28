
class Solution {
    public:
      int peakElement(vector<int> &arr) {
          // Your code here
          int ans = max_element(arr.begin(), arr.end()) - arr.begin();
          return ans;
      }
  };