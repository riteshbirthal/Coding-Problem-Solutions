class Solution {
    public:
      int lis(vector<int>& arr) {
          // code here
          int n = arr.size(), maxLen, res = 0;
          vector<int> vec(n, 0);
          for(int i = n-1; i >= 0; i--){
              maxLen = 1;
              for(int j = i+1; j < n; j++){
                  if(arr[i]<arr[j]){
                      maxLen = max(maxLen, 1 + vec[j]);
                  }
              }
              vec[i] = maxLen;
              res = max(res, maxLen);
          }
          return res;
      }
};