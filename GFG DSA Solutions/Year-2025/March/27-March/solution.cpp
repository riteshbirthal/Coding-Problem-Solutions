
class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          int n = arr.size(), res = n, left = 1, right = n, mid, isPossible;
          vector<vector<int>> vec;
          for(int i = 0; i < n; i++){
              vec.push_back({(arr[i]/100)*60 + arr[i]%100, (dep[i]/100)*60 + dep[i]%100});
          }
          sort(vec.begin(), vec.end());
          while(left<=right){
              mid = (left + right) / 2;
              priority_queue<int, vector<int>, greater<int>> pq;
              isPossible = 1;
              for(int i = 0; i < n && isPossible; i++){
                  while(pq.size() && pq.top()<vec[i][0])
                      pq.pop();
                  pq.push(vec[i][1]);
                  isPossible = pq.size()<=mid;
              }
              if(isPossible){
                  res = min(res, mid);
                  right = mid - 1;
              }else{
                  left = mid + 1;
              }
          }
          return res;
      }
  };
  
  