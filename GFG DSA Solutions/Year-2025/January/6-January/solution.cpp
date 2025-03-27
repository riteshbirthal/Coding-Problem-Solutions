// User function template for C++
class Solution {
    public:
      vector<int> sumClosest(vector<int>& arr, int target) {
          // code here
          if(arr.size()<2)
              return {};
          sort(arr.begin(), arr.end());
          int n = arr.size(), left = 0, right = n-1, sum = INT_MAX;
          vector<int> res, res1, res2;
          while(left<right && sum!=0){
              if(arr[left] + arr[right] > target){
                  sum = min(sum, arr[left] + arr[right] - target);
                  right--;
              }else{
                  sum = min(sum, target - arr[left] - arr[right]);
                  left++;
              }
          }
          unordered_map<int, int> u;
          for(int x : arr)
              u.find(x)==u.end() ? u[x] = 1 : u[x] += 1;
          int target1 = target-sum, target2 = target + sum;
          for(int i = 0; i < n-1; i++){
              if(2*arr[i]==target1 && u[arr[i]]>1){
                  res1 = {arr[i], arr[i]};
                  break;
              }else if(2*arr[i]!=target1 && u.find(target1-arr[i])!=u.end()){
                  res1 = {arr[i], target1-arr[i]};
                  break;
              }
          }
          for(int i = 0; i < n-1; i++){
              if(2*arr[i]==target2 && u[arr[i]]>1){
                  res2 = {arr[i], arr[i]};
                  break;
              }else if(2*arr[i]!=target2 && u.find(target2-arr[i])!=u.end()){
                  res2 = {arr[i], target2-arr[i]};
                  break;
              }
          }
          if(res1.size() && res2.size()){
              res = res1[1]-res1[0] < res2[1] - res2[0] ? res2 : res1;
          }else if(res1.size()){
              res = res1;
          }else{
              res = res2;
          }
          return res;
      }
  };