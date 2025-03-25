class Solution {
    public:
      int minJumps(vector<int>& arr) {
          // code here
          int n = arr.size();
          vector<int> vec(n, INT_MAX);
          vec[0] = 0;
          for(int i = 0; i < n && vec[n-1]==INT_MAX; i++){
              if(vec[i]!=INT_MAX){
                  for(int j = i+1; j <= min(i+arr[i], n-1); j++){
                      vec[j] = min(vec[j], 1 + vec[i]);
                  }
              }
          }
          return vec[n-1]==INT_MAX ? -1 : vec[n-1];
      }
  };
  
  