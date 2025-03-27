class Solution {
    public:
      // Function to count the number of possible triangles.
      int countTriangles(vector<int>& arr) {
          // code here
          sort(arr.begin(), arr.end());
          int n = arr.size(), left, right, mid, l_idx, r_idx, res = 0;
          for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){
                  left = j+1, right = n-1, l_idx = n;
                  while(left<=right){
                      mid = (left + right) / 2;
                      if(arr[mid]>arr[j]-arr[i]){
                          l_idx = mid;
                          right = mid - 1;
                      }else{
                          left = mid + 1;
                      }
                  }
                  left = j+1, right = n-1, r_idx = -1;
                  while(left<=right){
                      mid = (left + right) / 2;
                      if(arr[mid]<arr[j]+arr[i]){
                          r_idx = mid;
                          left = mid + 1;
                      }else{
                          right = mid - 1;
                      }
                  }
                  res += max(0, r_idx-l_idx+1);
              }
          }
          return res;
      }
  };
  