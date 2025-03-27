
class Solution {
    public:
      vector<int> countDistinct(vector<int> &arr, int k) {
          // code here.
          int n = arr.size();
          unordered_map<int, int> u;
          vector<int> res;
          for(int i = 0; i < n; i++){
              u.find(arr[i])==u.end() ? u[arr[i]] = 1 : u[arr[i]] += 1;
              if(i<k-1)
                  continue;
              res.push_back(u.size());
              u[arr[i-k+1]] == 1 ? u.erase(arr[i-k+1]) : u[arr[i-k+1]] -= 1;
          }
          return res;
      }
  };