// User function Template for C++

class Solution {
    public:
      int countSubarrays(vector<int> &arr, int k) {
          // code here
          int n = arr.size(), sum = 0, res = 0;
          unordered_map<int, int> u;
          u[0] = 1;
          for(int i = 0; i < n; i++){
              sum += arr[i];
              if(u.find(sum-k)!=u.end()) res += u[sum-k];
              u.find(sum)==u.end() ? u[sum] = 1 : u[sum] += 1;
          }
          return res;
      }
  };