class Solution {
    public:
      void mergeArrays(vector<int>& a, vector<int>& b) {
          // code here
          int n = a.size(), m = b.size();
          int i = n-1, j = 0, ele;
          while(i>=0 && j<m){
              if(a[i]>b[j]){
                  ele = a[i];
                  a[i] = b[j];
                  b[j] = ele;
              }
              i--, j++;
          }
          sort(a.begin(), a.end());
          sort(b.begin(), b.end());
      }
  };