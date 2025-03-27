class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          int res = 0, n = arr.size(), sum = 0;
          unordered_map<int, int> u;
          u[0] = -1;
          for(int i = 0; i < n; i++){
              sum += arr[i];
              if(u.find(sum-k)!=u.end())
                  res = max(res, i-u[sum-k]);
              if(u.find(sum)==u.end())
                  u[sum] = i;
          }
          return res;
      }
  };