class Solution {
    public:
      int longestUniqueSubstr(string &s) {
          // code here
          int n = s.size(), res = 0, left = 0, right = 0;
          unordered_map<int, int> u;
          while(right<n){
              u.find(s[right])==u.end() ? u[s[right]] = 1 : u[s[right]]++;
              while(u.size()!=right-left+1){
                  u[s[left]]==1 ? u.erase(s[left]) : u[s[left]]--;
                  left++;
              }
              res = max(res, right-left+1);
              right++;
          }
          return res;
      }
  };
  