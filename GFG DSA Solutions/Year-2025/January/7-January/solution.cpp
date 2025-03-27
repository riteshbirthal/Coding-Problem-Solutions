
class Solution {
    public:
      int countPairs(vector<int> &arr, int target) {
          // Complete the function
          unordered_map<int, int> u;
          int res = 0;
          for(int x : arr)
              u.find(x)==u.end() ? u[x] = 1 : u[x] += 1;
          for(auto x = u.begin(); x != u.end(); x++){
              if(2*x->first==target){
                  res += x->second * (x->second - 1);
              }else if(u.find(target-x->first)!=u.end()){
                  res += x->second * u[target-x->first];
              }
          }
          res /= 2;
          return res;
      }
  };