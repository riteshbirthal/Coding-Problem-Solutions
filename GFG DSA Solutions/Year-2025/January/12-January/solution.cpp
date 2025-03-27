class Solution {
    public:
      int maxWater(vector<int> &arr) {
          // code here
          int res = 0, n = arr.size(), mx = 0;
          vector<int> left = {0}, right = {0};
          for(int i = 1; i < n; i++){
              mx = max(mx, arr[i-1]);
              left.push_back(mx);
          }
          mx = 0;
          for(int i = n-2; i >= 0; i--){
              mx = max(mx, arr[i+1]);
              right.push_back(mx);
          }
          reverse(right.begin(), right.end());
          for(int i = 0; i < n; i++){
              res += max(0, min(left[i], right[i]) - arr[i]);
          }
          return res;
      }
  };