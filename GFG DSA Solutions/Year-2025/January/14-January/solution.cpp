class Solution {
    public:
      // Function to find equilibrium point in the array.
      int findEquilibrium(vector<int> &arr) {
          // code here
          int sum = 0, currentSum = 0, n = arr.size();
          for(int x : arr)
              sum += x;
          for(int i = 0; i < n; i++){
              if(2*currentSum == sum - arr[i]){
                  return i;
              }
              currentSum += arr[i];
          }
          return -1;
      }
  };