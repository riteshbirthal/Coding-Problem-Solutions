class Solution {
    public:
      int maxLen(vector<int> &arr) {
          // Your code here
          int res = 0, sum = 0, n = arr.size();
          unordered_map<int, int> u;
          for(int i = 0; i < n; i++){
              sum += (arr[i]==0) ? -1 : 1;
              if(sum==0)
                  res = i+1;
              u.find(sum)==u.end() ? u[sum] = i : res = max(res, i - u[sum]);
          }
          return res;
      }
  };
  