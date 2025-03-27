class Solution {
    public:
      long subarrayXor(vector<int> &arr, int k) {
          // code here
          unordered_map<int, int> u;
          u[0] = 1;
          int XOR = 0, res = 0;
          for(int x : arr){
              XOR ^= x;
              if(u.find(XOR^k)!=u.end()) res += u[XOR^k];
              u.find(XOR)==u.end() ? u[XOR] = 1 : u[XOR] += 1;
          }
          return res;
      }
  };