// User function template for C++

class Solution {
    public:
      vector<int> productExceptSelf(vector<int>& arr) {
          // code here
          vector<int> left = {1}, right = {1}, res;
          int n = arr.size();
          for(int i = 0; i < n; i++){
              left.push_back(left[i]*arr[i]);
              right.push_back(right[i]*arr[n-1-i]);
          }
          reverse(right.begin(), right.end());
          for(int i = 0; i < n; i++){
              res.push_back(left[i]*right[i+1]);
          }
          return res;
      }
  };
  