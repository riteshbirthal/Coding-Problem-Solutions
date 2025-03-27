class Solution {
    public:
      int maxWater(vector<int> &arr) {
          // code here
          int res = 0, start = 0, end = arr.size()-1;
          while(start<end){
              res = max(res, min(arr[start], arr[end]) * (end - start));
              if(arr[end]>arr[start]) start++;
              else end--;
          }
          return res;
      }
  };