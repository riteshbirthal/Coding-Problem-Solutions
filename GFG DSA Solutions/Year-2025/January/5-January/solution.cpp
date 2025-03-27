// User function Template for C++
class Solution {
    public:
      int countPairs(vector<int> &arr, int target) {
          // Your code here
          sort(arr.begin(), arr.end());
          int n = arr.size(), res = 0, left, right, mid, idx;
          for(int i = 0; i < n; i++){
              left = i, right = n-1, idx = i;
              while(left<=right){
                  mid = (left + right) / 2;
                  if(arr[i] + arr[mid] < target){
                      idx = mid;
                      left = mid + 1;
                  }else{
                      right = mid - 1;
                  }
              }
              res += idx - i;
          }
          return res;
      }
  };
  