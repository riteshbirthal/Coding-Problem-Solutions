class Solution {
    public:
      vector<int> subarraySum(vector<int> &arr, int target) {
          // code here
          int n = arr.size(), left = 0, right = 0, sum = 0;
          while(right<n){
              sum += arr[right];
              if(sum==target)
                  return {left+1, right+1};
              else if(sum<target)
                  right++;
              else
                  sum -= (arr[left]+arr[right]), left++;
          }
          return {-1};
      }
  };