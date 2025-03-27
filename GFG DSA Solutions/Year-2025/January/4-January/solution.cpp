class Solution {
    public:
      int countTriplets(vector<int> &arr, int target) {
          // Code Here
          int n = arr.size(), left, right, mid, idx1, idx2, res = 0;
          for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){
                  left = j+1, right = n-1, idx1 = -1;
                  while(left<=right){
                      mid = (left + right) / 2;
                      if(arr[i]+arr[j]+arr[mid]==target){
                          idx1 = mid;
                          right = mid-1;
                      }else if(arr[i]+arr[j]+arr[mid]>target){
                          right = mid-1;
                      }else{
                          left = mid+1;
                      }
                  }
                  if(idx1==-1)
                      continue;
                  left = j+1, right = n-1;
                  while(left<=right){
                      mid = (left + right) / 2;
                      if(arr[i]+arr[j]+arr[mid]==target){
                          idx2 = mid;
                          left = mid + 1;
                      }else if(arr[i]+arr[j]+arr[mid]>target){
                          right = mid - 1;
                      }else{
                          left = mid + 1;
                      }
                  }
                  res += idx2 - idx1 + 1;
              }
          }
          return res;
      }
  };